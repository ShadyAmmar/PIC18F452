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
#include "CCP1.h"
#include "ADC.h"
#include "UART.h"

DEVICE LED0 = {'B',0,OUTPUT};
DEVICE LED1 = {'B',1,OUTPUT};
DEVICE LED2 = {'B',2,OUTPUT};
DEVICE LED3 = {'C',2,OUTPUT};
DEVICE BTN0 = {'A',4,INPUT};


void main(void) {

    DIO_vdInit(&LED0);
    DIO_vdInit(&LED1);
    DIO_vdInit(&LED2);
    DIO_vdInit(&LED3);
    DIO_vdInit(&BTN0);
    
    INT_vdinit();
    ADC_vdInit();
    UART_vdInit(9600);
    
    while(1){
        UART_vdSendu16asASCI(ADC_u16getValue(AN0));   
        UART_vdSendByte('  ');
    }
    
    return;
}
