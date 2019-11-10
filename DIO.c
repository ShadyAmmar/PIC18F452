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
		case 'B':
			if(data){
				PORTBdata.PORT = data;
			}else{
				PORTBdata.PORT = 0;
			}
    }
}

void DIO_vdtogglePin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			PORTAdata.PORT ^= (1<<pin);
		case 'B':
			PORTBdata.PORT ^= (1<<pin);
	}
	
}

unsigned char DIO_u8ReadPin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			return (PORTAdata.PORT & (1<<pin))?1:0;
		case 'B':
			return (PORTBdata.PORT & (1<<pin))?1:0;
	}
	return 0;
}

unsigned char DIO_u8ReadPort(unsigned char port){
	switch(port){
		case 'A':
            return (PORTAdata.PORT);
		case 'B':
            return (PORTBdata.PORT);
	}
	return 0;
}