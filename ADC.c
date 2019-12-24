/* 
 * File:   ADC.c
 * Author: s.ammar
 *
 * Created on December 19, 2019, 2:16 PM
 */

#include "definitions.h"
#include <pic18.h>
#include <pic18f452.h>
#include "ADC.h"

void ADC_vdInit(){
    /*ADCON1bits.PCFG = PORT_CONFIG;
    ADCON1bits.ADFM = 0;
    ADCON0bits.ADCS = ADC_CLK_SRC;
    ADCON1bits.ADCS2 = (ADC_CLK_SRC>>2);
    ADCON0bits.ADON = 1;*/
    ADCON0 = 0x41; //ADC Module Turned ON and Clock is selected
   ADCON1 = 0xC0; //All pins as Analog Input
                 //With reference voltages VDD and VSS
}

unsigned short int ADC_u16getValue(unsigned char pin){
    /*ADCON0bits.CHS = pin;
    TRISA |= (1<<pin);
    ADCON0bits.GO = 1;
    while(!ADIF)  LATC2 = 1;
    LATC2 = 0;
    unsigned short int data = ( (ADRESH<<8)|(ADRESL) );
    ADIF = 0;
    return data;*/
    ADCON0 &= 0xC5; //Clearing the Channel Selection Bits
    ADCON0 |= pin<<3; //Setting the required Bits
    TRISA |= (1<<pin);
    __delay_ms(2); //Acquisition time to charge hold capacitor
    GO_nDONE = 1; //Initializes A/D Conversion
    while(GO_nDONE); //Wait for A/D Conversion to complete
    return ((ADRESH<<8)+ADRESL); //Returns Result
}