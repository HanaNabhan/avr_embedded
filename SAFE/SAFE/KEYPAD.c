/*
 * KEYPAD.c
 *
 * Created: 7/18/2024 10:30:07 PM
 *  Author: Hana Nabhan
 */ 
#include "STD_MACROS.h"
#include "DIO.h"
#include "BUTTON.h"
#include "KEYPAD.h"

#define PORTNAME 'A'


void KEYPAD_vInit(void){
	DIO_voidSetNibbleDir(PORTNAME,0x0f,0);
	DIO_voidSetNibbleDir(PORTNAME,0,1);
	// may cause problem if it is done on hardware can be fixed if it is connected pull up on hardware
	DIO_voidConnectPullUp(PORTNAME,4,1);
	DIO_voidConnectPullUp(PORTNAME,5,1);
	DIO_voidConnectPullUp(PORTNAME,6,1);
	DIO_voidConnectPullUp(PORTNAME,7,1);
}

uint8 KEYPAD_u8Read(void){
	uint8 row = 0;
	uint8 column = 0;
	uint8 return_value = NOTPRESSED;
	uint8 ascii_value[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
		
	for(row = 0 ; row < 4 ; row++) {
		DIO_voidWriteNibble(PORTNAME,0x0f,0);
		DIO_voidWritePin(PORTNAME,row,0);
		for(column = 0 ; column < 4 ; column++){
			if(0==BUTTON_u8Read(PORTNAME,column+4)){
				return_value=ascii_value[row][column];
				break;
			}
		}
		if (return_value != NOTPRESSED)
		{
			break;
		}
	}
	return return_value;
	
}