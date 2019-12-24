/* 
 * File:   ADC.h
 * Author: s.ammar
 *
 * Created on December 19, 2019, 2:16 PM
 */

#ifndef ADC_H
#define	ADC_H

#define ADC_CLK_SRC 0b001
#define PORT_CONFIG 0b0000  //pins0:7 are analog  - VDD & VSS used as reference

#define AN0 0
#define AN1 1
#define AN2 2
#define AN3 3
#define AN4 4
#define AN5 5
#define AN6 6
#define AN7 7

/*Prototypes*/
void ADC_vdInit();
unsigned short int ADC_u16getValue(unsigned char pin);

#endif	/* ADC_H */

