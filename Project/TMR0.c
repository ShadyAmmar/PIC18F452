/* 
 * File:   TMR0.c
 * Author: s.ammar
 *
 * Created on December 16, 2019, 4:31 PM
 */

#include <pic18f452.h>

#include "TMR0.h"
#include "INT.h"

static unsigned int initial = 0;

void TMR0_vdInit(unsigned char mode,unsigned char bits,unsigned char prescaler,unsigned char prescaler_value,unsigned int init){
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

    T0CONbits.T0SE = TMR0_EDGE;
    
    switch(prescaler){
        case PRE_SCALER_OFF:
            T0CONbits.PSA = 1;
            break;
        case PRE_SCALER_ON:
            T0CONbits.PSA = 0;
            break;
    }
    
    T0CONbits.T0PS = prescaler_value;
    initial = init;
    TMR0L = initial;
    TMR0H = (initial>>8);
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
    TMR0L = initial;
    TMR0H = (initial>>8);
    T0CONbits.TMR0ON = 1;
}

void TMR0_vdSetTMR0Callback(void (*pf)()){
    INT_vdSetTMR0Callback(pf,initial);
}