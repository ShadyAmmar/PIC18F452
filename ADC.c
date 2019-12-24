/* 
 * File:   ADC.c
 * Author: s.ammar
 *
 * Created on December 19, 2019, 2:16 PM
 */

#include <pic18f452.h>
#include "ADC.h"

void ADC_vdInit(){
    ADCON1bits.PCFG = PORT_CONFIG;
    ADCON1bits.ADFM = 0;
    ADCON0bits.ADCS = ADC_CLK_SRC;
    ADCON1bits.ADCS2 = (ADC_CLK_SRC>>2);
    ADCON0bits.ADON = 1;
}

unsigned short int ADC_u16getValue(unsigned char pin){
    ADCON0bits.CHS = pin;
    TRISA |= (1<<pin);
    ADCON0bits.GO = 1;
    while(!ADIF)  LATC2 = 1;
    LATC2 = 0;
    unsigned short int data = ( (ADRESH<<8)|(ADRESL) );
    ADIF = 0;
    return data;
}