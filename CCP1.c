/* 
 * File:   CCP1.c
 * Author: s.ammar
 *
 * Created on December 17, 2019, 11:26 AM
 */

#include <pic18f452.h>

#include "CCP1.h"

void CCP1_vdInit(unsigned char mode){
    CCP1CONbits.CCP1M = CCP1_DISABLE;
    
    CCP1CONbits.CCP1M = mode;
}
