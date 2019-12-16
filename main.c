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

DEVICE LED0 = {'B',0,OUTPUT};
DEVICE BTN0 = {'B',1,INPUT};

void callback_INT1();

void main(void) {

    DIO_vdInit(&LED0);
    DIO_vdInit(&BTN0);
    INT_vdinit();
    INT_vdSetINT1Callback(callback_INT1);
    
    while(1){
        /*if(BTN_u8getStatus(&BTN0)){
            LED_vdOn(&LED0);
        }else{
            LED_vdOff(&LED0);
        }*/      
        
    }
    
    return;
}

void callback_INT1(){
    LED_vdtoggle(&LED0);
}
