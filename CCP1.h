/* 
 * File:   CCP1.h
 * Author: s.ammar
 *
 * Created on December 17, 2019, 11:26 AM
 */

#ifndef CCP1_H
#define	CCP1_H

#define CCP1_DISABLE        0b0000

#define CAPTURE_FALLING     0b0100
#define CAPTURE_RISING      0b0101
#define CAPTURE_4TH_RISING  0b0110
#define CAPTURE_16TH_RISING 0b0111

/*Prototypes*/
void CCP1_vdInit(unsigned char mode);

#endif	/* CCP1_H */

