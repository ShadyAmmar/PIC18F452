/* 
 * File:   BTN.h
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 6:52 PM
 */

#ifndef BTN_H
#define	BTN_H

#include "definitions.h"

#define pressed 1
#define released 0
#define err 3
unsigned char BTN_u8getFilteredStatus(DEVICE* btn);
void BTN_vdRead(DEVICE* btn);
unsigned char BTN_u8getStatus(DEVICE* btn);

#endif	/* BTN_H */

