/*
 * File:   DIO.c
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 3:26 PM
 */

#include <xc.h>
#include "INT.h" 

static void (*callback_INT0)();
static void (*callback_INT1)();
static void (*callback_INT2)();
static void (*callback_INTonChange)();

void INT_vdinit(void){
    INTCON1bits.GIE = ENABLED;
    
    /*Edge-triggered interrupts*/
    INTCON1bits.INT0IE = INT0_ENABLE;
    INTCON3bits.INT1IE = INT1_ENABLE;
    INTCON3bits.INT2IE = INT2_ENABLE;
    
    INTCON2bits.INTEDG0 = INT0_EDGE;
    INTCON2bits.INTEDG1 = INT1_EDGE;
    INTCON2bits.INTEDG2 = INT2_EDGE;
    
    /*Level Change interrupt*/
    INTCON1bits.RBIE = PORTB_INT_ON_CHANGE;
}

void INT_vdSetINT0Callback(void (*pf)()){
    callback_INT0 = pf;
}
void INT_vdSetINT1Callback(void (*pf)()){
    callback_INT1 = pf;
}
void INT_vdSetINT2Callback(void (*pf)()){
    callback_INT2 = pf;
}
void INT_vdSetINTOnChangeCallback(void (*pf)()){
    callback_INTonChange = pf;
}

void __interrupt () ISR(){
    /**********Edge Triggered interrupt on PORTB pins:0,1,2********************/
    if(INT0IF){
        callback_INT0();
        INT0IF = 0;
    }
    if(INT1IF){
        callback_INT1();
        INT1IF = 0;
    }
    if(INT2IF){
        callback_INT2();
        INT2IF = 0;
    }
    if(RBIF){
        callback_INTonChange();
        RBIF = 0;
    }
}