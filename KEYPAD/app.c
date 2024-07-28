/*
 * KEYPAD.c
 *
 * Created: 7/18/2024 10:30 PM
 *  Author: Hana Nabhan
 */ 


#include <avr/io.h>
#include <util/delay.h>

#include "STD_MACROS.h"
#include "DIO.h"
#include "BUTTON.h"
#include "LCD.h"
#include "KEYPAD.h"

#define NOTPRESSED 0Xff


int main (void){
	LCD_vInit();
	KEYPAD_vInit();	
	while (1)
	{
		if (KEYPAD_u8Read()!= NOTPRESSED)
		{
			if(KEYPAD_u8Read()=='A'){
				LCD_vCLR();
			}
			else{
			LCD_vSendData(KEYPAD_u8Read());
			}			
		}
		_delay_ms(200);
	}
}
