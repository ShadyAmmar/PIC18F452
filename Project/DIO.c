/*
 * File:   DIO.c
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 3:26 PM
 */


#include <xc.h>
#include "definitions.h"
#include "DIO.h" 



void DIO_vdInit(DEVICE* dev){
    DIO_vdWriteDirPin(dev->mode,dev->PORT,dev->pin);
}

void DIO_vdWritePin(unsigned char data,unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			if(data){
				PORTAdata.PORT |= (1<<pin); 
			}else{
				PORTAdata.PORT &= ~(1<<pin);
			}
            break;
		case 'B':
			if(data){
				PORTBdata.PORT |= (1<<pin);
				}else{
				PORTBdata.PORT &= ~(1<<pin);
			}
            break;
        case 'C':
			if(data){
				PORTCdata.PORT |= (1<<pin);
				}else{
				PORTCdata.PORT &= ~(1<<pin);
			}
            break;
        case 'D':
			if(data){
				PORTDdata.PORT |= (1<<pin);
				}else{
				PORTDdata.PORT &= ~(1<<pin);
			}
            break;
	}	
}

void DIO_vdWriteDirPin(unsigned char data,unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			if(data){
				PORTAdirection.PORT |= (1<<pin); 
			}else{
				PORTAdirection.PORT &= ~(1<<pin);
			}
            break;
		case 'B':
			if(data){
				PORTBdirection.PORT |= (1<<pin);
				}else{
				PORTBdirection.PORT &= ~(1<<pin);
			}
            break;
        case 'C':
			if(data){
				PORTCdirection.PORT |= (1<<pin);
				}else{
				PORTCdirection.PORT &= ~(1<<pin);
			}
            break;
        case 'D':
			if(data){
				PORTDdirection.PORT |= (1<<pin);
				}else{
				PORTDdirection.PORT &= ~(1<<pin);
			}
            break;
	}	
}

void DIO_vdWritePort(unsigned char data,unsigned char port){
	switch(port){
		case 'A':
			if(data){
				PORTAdata.PORT = data;
			}else{
				PORTAdata.PORT = 0;
			}
            break;
		case 'B':
			if(data){
				PORTBdata.PORT = data;
			}else{
				PORTBdata.PORT = 0;
			}
            break;
        case 'C':
			if(data){
				PORTCdata.PORT = data;
			}else{
				PORTCdata.PORT = 0;
			}
            break;
        case 'D':
			if(data){
				PORTDdata.PORT = data;
			}else{
				PORTDdata.PORT = 0;
			}
            break;
    }
}

void DIO_vdtogglePin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			PORTAdata.PORT ^= (1<<pin);
            break;
		case 'B':
			PORTBdata.PORT ^= (1<<pin);
            break;
        case 'D':
			PORTDdata.PORT ^= (1<<pin);
            break;
	}
	
}

unsigned char DIO_u8ReadPin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			return (PORTAdata.PORT & (1<<pin))?1:0;
		case 'B':
			return (PORTBdata.PORT & (1<<pin))?1:0;
        case 'D':
			return (PORTDdata.PORT & (1<<pin))?1:0;
	}
	return 0;
}

unsigned char DIO_u8ReadPort(unsigned char port){
	switch(port){
		case 'A':
            return (PORTAdata.PORT);
		case 'B':
            return (PORTBdata.PORT);
        case 'D':
            return (PORTDdata.PORT);
	}
	return 0;
}