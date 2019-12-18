/* 
 * File:   CCP1.h
 * Author: s.ammar
 *
 * Created on December 17, 2019, 11:26 AM
 */

#ifndef CCP1_H
#define	CCP1_H

#define CCP1_DISABLE        0b0000

#define CAPTURE_FALLING         0b0100
#define CAPTURE_RISING          0b0101
#define CAPTURE_4TH_RISING      0b0110
#define CAPTURE_16TH_RISING     0b0111
#define COMPARE_TGL_ON_MATCH    0b0001
#define COMPARE_HIGH_ON_MATCH   0b1000
#define COMPARE_LOW_ON_MATCH    0b1001
#define COMPARE_SW_INT_ON_MATCH 0b1010
#define COMPARE_SPECIAL_EVENT   0b1011
#define PWM_MODE                0b1100

#define T1_CCPs         0b00
#define T3_CCPs         0b10
#define T1_CCP1_T3_CCP2 0b01

#define TMR2_PRESCALE_1  0b00
#define TMR2_PRESCALE_4  0b01
#define TMR2_PRESCALE_16 0b10

/*Configurations*/
#define TIMER_USED  T1_CCPs


/*Prototypes*/
void CCP1_vdInit(unsigned char mode,unsigned char TMR2_prescale,unsigned long int PWM_freq);
unsigned short int CCP1_u16getCCPR();
unsigned char CCP1_u8getCCPR();
void CCP1_vdSetCCPR(unsigned short int value);
void CCP1_vdSetDutyCycle(unsigned char duty);

#endif	/* CCP1_H */

