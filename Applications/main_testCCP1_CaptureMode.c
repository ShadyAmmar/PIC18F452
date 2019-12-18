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
#include "TMR1.h"
#include "CCP1.h"


DEVICE LED0 = {'B',0,OUTPUT};
DEVICE LED1 = {'B',1,OUTPUT};
DEVICE LED2 = {'B',2,OUTPUT};
DEVICE BTN0 = {'A',4,INPUT};


void main(void) {

    DIO_vdInit(&LED0);
    DIO_vdInit(&LED1);
    DIO_vdInit(&LED2);
    DIO_vdInit(&BTN0);
    
    INT_vdinit();
    TMR1_vdInit(COUNTER,R_W_8BIT,PRE_SCALER_OFF,0);
    CCP1_vdSetCCPR(3);
    CCP1_vdInit(COMPARE_HIGH_ON_MATCH);
    
    while(1){
        PORTB = TMR1L; 
    }
    
    return;
}
