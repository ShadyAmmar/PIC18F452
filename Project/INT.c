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
static void (*callback_TMR0)();
static void (*callback_TMR1)();
static void (*callback_TMR3)();
static void (*callback_CCP1)();

static unsigned int initial_tmr0 = 0;
static unsigned int initial_tmr1 = 0;
static unsigned int initial_tmr3 = 0;

void INT_vdinit(void){
    INTCON1bits.GIE = ENABLED;
    PEIE = 1;         //Enable the Peripheral Interrupt
    
    /*Edge-triggered interrupts*/
    INTCON1bits.INT0IE = INT0_ENABLE;
    INTCON3bits.INT1IE = INT1_ENABLE;
    INTCON3bits.INT2IE = INT2_ENABLE;
    
    INTCON2bits.INTEDG0 = INT0_EDGE;
    INTCON2bits.INTEDG1 = INT1_EDGE;
    INTCON2bits.INTEDG2 = INT2_EDGE;
    
    /*Level Change interrupt*/
    INTCON1bits.RBIE = PORTB_INT_ON_CHANGE;
    
    /*Timer0 overflow interrupt*/
    INTCON1bits.TMR0IE = TMR0_INT;
    
    /*Timer1 overflow interrupt*/
    TMR1IF = 0; 
    PIE1bits.TMR1IE = TMR1_INT;
    IPR1bits.TMR1IP = 0;        //non high priority interrupt
    
    /*Timer3 overflow interrupt*/
    TMR3IF = 0; 
    PIE2bits.TMR3IE = TMR3_INT;
    IPR2bits.TMR3IP = 0;        //non high priority interrupt
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
void INT_vdSetTMR0Callback(void (*pf)(),unsigned int init){
    callback_TMR0 = pf;
    initial_tmr0 = init;
}
void INT_vdSetTMR1Callback(void (*pf)(),unsigned int init){
    callback_TMR1 = pf;
    initial_tmr1 = init;
}
void INT_vdSetTMR3Callback(void (*pf)(),unsigned int init){
    callback_TMR3 = pf;
    initial_tmr3 = init;
}
void INT_vdSetCCP1Callback(void (*pf)()){
    callback_CCP1 = pf;
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
    
    /*Timer0 Overflow interrupt*/
    if(TMR0IF){
        callback_TMR0();
        TMR0L = initial_tmr0;
        TMR0H = (initial_tmr0>>8);
        TMR0IF = 0;
    }
    
    /*Timer1 Overflow interrupt*/
    if(TMR1IF){
        callback_TMR1();
        TMR1L = initial_tmr1;
        TMR1H = (initial_tmr1>>8);
        TMR1IF = 0;
    }
    
    /*Timer3 Overflow interrupt*/
    if(TMR3IF){
        callback_TMR3();
        TMR3L = initial_tmr3;
        TMR3H = (initial_tmr3>>8);
        TMR3IF = 0;
    }
    
    /*CCP1 interrupt*/
    if(CCP1IF){
        callback_CCP1();
        CCP1IF = 0;
    }
}