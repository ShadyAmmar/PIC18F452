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
#include "ADC.h"
#include "UART.h"

DEVICE LED1 = {'D',0,OUTPUT};
DEVICE LED2 = {'D',1,OUTPUT};
DEVICE LED3 = {'D',2,OUTPUT};

DEVICE BTN1 = {'B',0,INPUT};
DEVICE BTN2 = {'B',1,INPUT};
DEVICE BTN3 = {'B',2,INPUT};

void int0_callback();
void int1_callback();
void int2_callback();

void main(void) {

    DIO_vdInit(&LED1);
    DIO_vdInit(&LED2);
    DIO_vdInit(&LED3);
    DIO_vdInit(&BTN1);
    DIO_vdInit(&BTN2);
    DIO_vdInit(&BTN3);
    
    INT_vdinit();
    INT_vdSetINT0Callback(int0_callback);
    INT_vdSetINT1Callback(int1_callback);
    INT_vdSetINT2Callback(int2_callback);
    
    TMR0_vdInit(TIMER,BIT8,0,PRE_SCALER_ON,TMR0_SCALE_256);
    
    ADC_vdInit();
    
    UART_vdInit(9600);
    
    while(1){
        UART_vdSendu8asASCI(TMR0L);
        UART_vdSendByte(' ');
    }
    
    return;
}

void int0_callback(){
    LED_vdtoggle(&LED1);
    TMR0_vdStop();
}

void int1_callback(){
    LED_vdtoggle(&LED2);
    TMR0_vdContinue();
}

void int2_callback(){
    LED_vdtoggle(&LED3);
}