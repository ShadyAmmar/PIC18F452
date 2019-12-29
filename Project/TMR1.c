/* 
 * File:   TMR1.c
 * Author: s.ammar
 *
 * Created on December 18, 2019, 11:23 AM
 */

#include <pic18f452.h>

#include "TMR1.h"

static unsigned int initial = 0;

void TMR1_vdInit(unsigned char mode,unsigned char bits,unsigned char prescaler,unsigned char prescaler_value,unsigned int init){
    switch(mode){
        case COUNTER:
            T1CONbits.TMR1CS = EXT_CLK;
            break;
        case TIMER:
            T1CONbits.TMR1CS = INT_CLK;
            break;
    }
    
    T1CONbits.RD16 = bits;
    
    switch(prescaler){
        case PRE_SCALER_OFF:
            T1CONbits.T1CKPS = 0;
            break;
        case PRE_SCALER_ON:
            T1CONbits.T1CKPS = prescaler_value;
            break;
    }
    
    T1CONbits.T1OSCEN = 0;
    TMR1IF = 0; 
    TMR1L = initial;
    TMR1H = (initial>>8);
    T1CONbits.TMR1ON = 1;
}

void TMR1_vdStop(){
    T1CONbits.TMR1ON = 0;
}

void TMR1_vdContinue(){
    T1CONbits.TMR1ON = 1;
}

void TMR1_vdReset(){
    T1CONbits.TMR1ON = 0;
    TMR1L = initial;
    TMR1H = (initial>>8);
    T1CONbits.TMR1ON = 1;
}