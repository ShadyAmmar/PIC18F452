/*
 * File:   main.c
 * Author: Shady Ammar
 *
 * Created on November 8, 2019, 8:59 PM
 */


#include <xc.h>

#include "definitions.h"    //registers and their accessing structures + general definitions
#include "config.h"         //Fuse bits
#include "DIO.h"            
#include "LED.h"
#include "BTN.h"
#include "INT.h"
#include "TMR0.h"
#include "TMR1.h"
#include "TMR3.h"
#include "ADC.h"
#include "UART.h"

DEVICE LED1 = {'D',0,OUTPUT};
DEVICE LED2 = {'D',1,OUTPUT};
DEVICE LED3 = {'D',2,OUTPUT};
DEVICE LED4 = {'D',3,OUTPUT};

DEVICE BTN1 = {'B',0,INPUT};
DEVICE BTN2 = {'B',1,INPUT};
DEVICE BTN3 = {'B',2,INPUT};

DEVICE btnStop1 = {'B',3,INPUT};
DEVICE btnStop2 = {'B',4,INPUT};
DEVICE btnStop3 = {'B',5,INPUT};

void int0_callback();
void int1_callback();
void int2_callback();
void tmr0_callback();
void tmr1_callback();
void tmr3_callback();

volatile unsigned char status1 = 0;
volatile unsigned char status2 = 0;
volatile unsigned char status3 = 0;

volatile unsigned long int x1 = 0;
volatile unsigned long int x2 = 0;
volatile unsigned long int x3 = 0;

void main(void) {

    DIO_vdInit(&LED1);
    DIO_vdInit(&LED2);
    DIO_vdInit(&LED3);
    DIO_vdInit(&LED4);
    DIO_vdInit(&BTN1);
    DIO_vdInit(&BTN2);
    DIO_vdInit(&BTN3);
    DIO_vdInit(&btnStop1);
    DIO_vdInit(&btnStop2);
    DIO_vdInit(&btnStop3);
    
    INT_vdinit();
    INT_vdSetINT0Callback(int0_callback);
    INT_vdSetINT1Callback(int1_callback);
    INT_vdSetINT2Callback(int2_callback);
    
    TMR0_vdInit(TIMER,BIT8,PRE_SCALER_ON,TMR0_SCALE_256,11);
    TMR0_vdStop();
    TMR0_vdSetTMR0Callback(tmr0_callback);
    
    TMR1_vdInit(TIMER,BIT8,PRE_SCALER_OFF,0,3050);
    TMR1_vdStop();
    TMR1_vdSetTMR1Callback(tmr1_callback);
    
    TMR3_vdInit(TIMER,BIT8,PRE_SCALER_OFF,0,3050);
    TMR3_vdStop();
    TMR3_vdSetTMR3Callback(tmr3_callback);
    
    ADC_vdInit();
    
    UART_vdInit(9600);
    
    unsigned int input_T;
    unsigned char T;
    unsigned long long int x_max8;
    unsigned long long int x_max16;
    while(1){
        input_T = ADC_u16getValue(AN0);
        T = 50*input_T/1023 + 10;
        //UART_vdSendu16asASCI(input_T);
        //UART_vdSendByte(' ');
        //UART_vdSendu16asASCI(T);
        //UART_vdSendByte('/');
        x_max8 = T * 12;
        //UART_vdSendu16asASCI(x_max);
        //UART_vdSendByte(' ');
        x_max16 = T * 13;
        if(x1 == x_max8){
            TMR0_vdStop();
            x1 = 0;
            status1 = !status1;
        }
        if(x2 == x_max16){
            TMR1_vdStop();
            x2 = 0;
            status2 = !status2;
        }
        if(x3 == x_max16){
            TMR3_vdStop();
            x3 = 0;
            status3 = !status3;
        }
        
        /*Stop buttons*/
        if(BTN_u8getStatus(&btnStop1)){
            TMR0_vdStop();
            status1 = 0;
        }
        if(BTN_u8getStatus(&btnStop2)){
            TMR1_vdStop();
            status2 = 0;
        }
        if(BTN_u8getStatus(&btnStop3)){
            TMR3_vdStop();
            status3 = 0;
        }
        
        LED_vdSetStatus(&LED1,status1);
        LED_vdSetStatus(&LED2,status2);
        LED_vdSetStatus(&LED3,status3);
        UART_vdSendu8asASCI(T);
        UART_vdSendByte('/');
        /*UART_vdSendu16asASCI((TMR1H<<8)|TMR1L);
        UART_vdSendByte('/');
        UART_vdSendu8asASCI(x_max16);
        UART_vdSendByte(' ');*/
        
        LED_vdSetStatus(&LED4, (status1||status2||status3) );
        __delay_ms(10);
    }
    
    return;
}

void int0_callback(){
    if(!status1){
        status1 = 1;
        TMR0_vdReset();
    }
    
}

void int1_callback(){
    if(!status2){
        status2 = 1;
        TMR1_vdReset();
    }
}

void int2_callback(){
    if(!status3){
        status3 = 1;
        TMR3_vdReset();
    }
}

void tmr0_callback(){
    x1++;
}

void tmr1_callback(){
    x2++;
}

void tmr3_callback(){
    x3++;
}