/* 
 * File:   CCP1.c
 * Author: s.ammar
 *
 * Created on December 17, 2019, 11:26 AM
 */

#include <pic18f452.h>

#include "CCP1.h"
#include "definitions.h"

static unsigned char prescaler_TMR2 = 1;
static unsigned long int freq_PWM = 500000;

void CCP1_vdInit(unsigned char mode,unsigned char TMR2_prescale,unsigned long int PWM_freq){
    CCP1CONbits.CCP1M = CCP1_DISABLE;
    T3CONbits.T3CCP1 = TIMER_USED;
    T3CONbits.T3CCP2 = (TIMER_USED>>1);
    switch(mode){
        case COMPARE_HIGH_ON_MATCH:
        case COMPARE_LOW_ON_MATCH:
        //case COMPARE_SPECIAL_EVENT:
        //case COMPARE_SW_INT_ON_MATCH: 
        case COMPARE_TGL_ON_MATCH:
            TRISCbits.RC2 = 0;
            break;
        case PWM_MODE:
            freq_PWM = PWM_freq;
            switch(TMR2_prescale){
                case TMR2_PRESCALE_1:
                    prescaler_TMR2 = 1;
                    break;
                case TMR2_PRESCALE_4:
                    prescaler_TMR2 = 4;
                    break;
                case TMR2_PRESCALE_16:
                    prescaler_TMR2 = 16;
                    break;
            }
            
            //Calculate PR2
            PR2 = _XTAL_FREQ /PWM_freq/4/prescaler_TMR2 - 1;
            //PR2 = 124;
            TRISCbits.RC2 = 0;
            T2CONbits.T2CKPS = TMR2_prescale;
            T2CONbits.TMR2ON = 1;
            return;
    }
    CCP1CONbits.CCP1M = mode;
}

void CCP1_vdSetDutyCycle(unsigned char duty){
    unsigned char DC = duty * _XTAL_FREQ / 100 / freq_PWM / prescaler_TMR2;
    //DC = 250;
    CCP1CONbits.CCP1M0 = DC;
    CCP1CONbits.CCP1M1 = (DC>>1);
    CCPR1L = (DC>>2);
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M3 = 1;
}

void CCP1_vdSetCCPR(unsigned short int value){
    CCPR1L = (unsigned char) value;
    CCPR1H = (unsigned char) (value>>8);
}

unsigned short int CCP1_u16getCCPR(){
    return ( (CCPR1H<<8)|(CCPR1L) );
}

unsigned char CCP1_u8getCCPR(){
    return ( (CCPR1L) );
}