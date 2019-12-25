/* 
 * File:   TMR0.c
 * Author: s.ammar
 *
 * Created on December 16, 2019, 4:31 PM
 */

#include <pic18f452.h>

#include "TMR0.h"


void TMR0_vdInit(unsigned char mode,unsigned char bits,unsigned char edge,unsigned char prescaler,unsigned char prescaler_value){
    switch(mode){
        case COUNTER:
            T0CONbits.T0CS = 1;
            break;
        case TIMER:
            T0CONbits.T0CS = 0;
            break;
    }
    switch(bits){
        case BIT8:
            T0CONbits.T08BIT = 1;
            break;
        case BIT16:
            T0CONbits.T08BIT = 0;
            break;
    }
    switch(edge){
        case HIGH_TO_LOW:
            T0CONbits.T0SE = 1;
            break;
        case LOW_TO_HIGH:
            T0CONbits.T0SE = 0;
            break;
    }
    switch(prescaler){
        case PRE_SCALER_OFF:
            T0CONbits.PSA = 1;
            break;
        case PRE_SCALER_ON:
            T0CONbits.PSA = 0;
            break;
    }
    
    T0CONbits.T0PS = prescaler_value;
    
    T0CONbits.TMR0ON = 1;
}

void TMR0_vdStop(){
    T0CONbits.TMR0ON = 0;
}

void TMR0_vdContinue(){
    T0CONbits.TMR0ON = 1;
}

void TMR0_vdReset(){
    T0CONbits.TMR0ON = 0;
    TMR0L = 0;
    TMR0H = 0;
    T0CONbits.TMR0ON = 1;
}