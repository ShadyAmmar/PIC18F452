/* 
 * File:   TMR3.c
 * Author: s.ammar
 *
 * Created on December 30, 2019
 */

#include <pic18f452.h>

#include "TMR3.h"
#include "INT.h"

static unsigned int initial = 0;

void TMR3_vdInit(unsigned char mode,unsigned char bits,unsigned char prescaler,unsigned char prescaler_value,unsigned int init){
    switch(mode){
        case COUNTER:
            T3CONbits.TMR3CS = EXT_CLK;
            break;
        case TIMER:
            T3CONbits.TMR3CS = INT_CLK;
            break;
    }
    
    T3CONbits.RD16 = bits;
    
    switch(prescaler){
        case PRE_SCALER_OFF:
            T3CONbits.T3CKPS = 0;
            break;
        case PRE_SCALER_ON:
            T3CONbits.T3CKPS = prescaler_value;
            break;
    }
    

    TMR3IF = 0; 
    initial = init;
    TMR3L = initial;
    TMR3H = (initial>>8);
    T3CONbits.TMR3ON = 1;
}

void TMR3_vdStop(){
    T3CONbits.TMR3ON = 0;
}

void TMR3_vdContinue(){
    T3CONbits.TMR3ON = 1;
}

void TMR3_vdReset(){
    T3CONbits.TMR3ON = 0;
    TMR3L = initial;
    TMR3H = (initial>>8);
    T3CONbits.TMR3ON = 1;
}

void TMR3_vdSetTMR3Callback(void (*pf)()){
    INT_vdSetTMR3Callback(pf,initial);
}