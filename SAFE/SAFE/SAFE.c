/*
 * SAFE.c
 *
 * Created: 7/28/2024 5:17:11 PM
 *  Author: Hana Nabhan
 */ 


#include <util/delay.h>
#include "STD_MACROS.h"
#include "KEYPAD.h"
#include "EEPROM.h"
#include "LCD.h"


#define F_CPU 8000000UL
#define EEPROM_STATUS_LOC  0X20
#define EEPROM_PASS_LOC1  0X21
#define EEPROM_PASS_LOC2  0X22
#define EEPROM_PASS_LOC3  0X23
#define EEPROM_PASS_LOC4  0X24
#define MAXTRIES 3


uint8 pass[4] ;
uint8 i;
uint8 val = NOTPRESSED;

void SET_PASS(void){

	LCD_vSendString("SET PASS : ");
	for(i=0;i<4;i++){
		do{
			val=KEYPAD_u8Read();
			
		}while(val == NOTPRESSED);
		LCD_vSendData(val);
		_delay_ms(500);
		LCD_vMoveCursor(1,12+i);
		LCD_vSendData('*');
		EEPROM_vWrite(EEPROM_PASS_LOC1+i,val);
	}
	EEPROM_vWrite(EEPROM_STATUS_LOC,0X00);
}

int main(void)
{
	
	uint8 flag =0 ;
	uint8 tries = MAXTRIES;
	KEYPAD_vInit();
	LCD_vInit();
	if(EEPROM_u8Read(EEPROM_STATUS_LOC) == NOTPRESSED){
		SET_PASS();	
		
	}		
	while(flag==0){
		LCD_vCLR();
		LCD_vSendString("ENTER PASS:");
		for(i=0;i<4;i++){
			do{
				pass[i]=KEYPAD_u8Read();
				
			}while(pass[i] == NOTPRESSED);
			LCD_vSendData(pass[i]);
			_delay_ms(500);
			LCD_vMoveCursor(1,12+i);
			LCD_vSendData('*');
		}
		if(EEPROM_u8Read(EEPROM_PASS_LOC1)==pass[0] && EEPROM_u8Read(EEPROM_PASS_LOC2)==pass[1] && EEPROM_u8Read(EEPROM_PASS_LOC3)==pass[2]  &&   EEPROM_u8Read(EEPROM_PASS_LOC4)==pass[3]){
			LCD_vCLR();
			LCD_vMoveCursor(1,1);
			LCD_vSendString("PASSWORD RIGHT");
			LCD_vMoveCursor(2,1);
			LCD_vSendString("SAFE OPENED");
			flag=1;
			
		}
		else{
			tries--;
			if(tries>0){
				LCD_vCLR();
				LCD_vMoveCursor(1,1);
				LCD_vSendString("PASSWORD WRONG");
				LCD_vMoveCursor(2,1);
				LCD_vSendString("TRIES LEFT : ");
				LCD_vSendData(tries+48);
				_delay_ms(1000);
				
			}
			else{
				LCD_vCLR();
				LCD_vMoveCursor(1,1);
				LCD_vSendString("PASSWORD WRONG");
				LCD_vMoveCursor(2,1);
				LCD_vSendString("SAFE CLOSED");
				flag=1;
			}
			
		}
	}		
  
}
