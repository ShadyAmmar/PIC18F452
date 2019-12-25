/* 
 * File:   BTN.c
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 6:52 PM
 */

#include "BTN.h"
#include "DIO.h"


static unsigned char BTNstatus[] = {0,0,0,0,0,0,0,0};   //For multi BTNs

unsigned char BTN_u8getFilteredStatus(DEVICE* btn){
	switch( btn->status )
	{
		case 1 :
		return pressed;
		break;
		case 0 :
		return released;
		break;
		case 3 :
		return err;
		break;
	}
	return pressed;
}

/*this function treats the bouncing by ignoring the bouncing phase and start
count when the signal becomes stable
i used to count the duration of stable signal
j used to trace if the high signal remains for long time which indicates error
finally this function changes the BTNstatus[pin] ==> (pressed , released , error)*/
/*We can delete j counter & use condition (i%3==0) to check stability*/
void BTN_vdRead(DEVICE* btn){
	unsigned char temp2 = DIO_u8ReadPin(btn->PORT,btn->pin);
	
	if(btn->temp1 == temp2){		/*if signal is stable continues counting*/
		(btn->i)++;
	}else{
		btn->temp1 = temp2;			/*if signal changed reset the count*/
		btn->i =1;
	}
		
	if(btn->i % 3 == 0){		/*if signal is stable until count is 3, catch the BTNstatus and reset the i counter*/
		btn->status = temp2;
		btn->i =0;
	}
		
	if(btn->i == 400 && btn->status==pressed){	 /*if signal is sticked to high ==> error*/
		btn->status = err;
		btn->i = 0;
	}
}

unsigned char BTN_u8getStatus(DEVICE* btn){
	return DIO_u8ReadPin(btn->PORT,btn->pin);
}


