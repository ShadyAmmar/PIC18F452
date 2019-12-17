/*
 * File:   main.c
 * Author: Shady Ammar
 *
 * Created on November 8, 2019, 8:59 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000

#include "definitions.h"    //registers and their accessing structures + general definitions
#include "config.h"         //Fuse bits
#include "DIO.h"            
#include "LED.h"
#include "BTN.h"
#include "INT.h"
#include "TMR0.h"

DEVICE LED0 = {'B',0,OUTPUT};
DEVICE LED1 = {'B',1,OUTPUT};
DEVICE LED2 = {'B',2,OUTPUT};
DEVICE BTN0 = {'A',4,INPUT};

void callback_INTonChange();
void callback_TMR0();

void main(void) {

    DIO_vdInit(&LED0);
    DIO_vdInit(&LED1);
    DIO_vdInit(&LED2);
    DIO_vdInit(&BTN0);
    
    INT_vdinit();
    //INT_vdSetINTOnChangeCallback(callback_INTonChange);
    INT_vdSetTMR0Callback(callback_TMR0);
    
    TMR0_vdInit(TIMER,BIT8,0,PRE_SCALER_ON,SCALE_16);
    //TMR0_vdInit(COUNTER,BIT8,LOW_TO_HIGH,PRE_SCALER_OFF,0);
    
    
    while(1){
        /*if(BTN_u8getStatus(&BTN0)){
            LED_vdOn(&LED0);
        }else{
            LED_vdOff(&LED0);
        }*/      
        
    }
    
    return;
}

void callback_INTonChange(){
    LED_vdtoggle(&LED0);
}

void callback_TMR0(){
    static unsigned char counter = 0;
    counter++;
    if(counter == 245){
        counter =0;
        LED_vdtoggle(&LED0);
    }   
}
