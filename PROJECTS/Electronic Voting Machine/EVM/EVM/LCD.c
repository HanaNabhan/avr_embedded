/*
 * LCD.c
 *
 * Created: 6/9/2023 12:10:12 AM
 *  Author: Hana Nabhan
 */ 
#include <util/delay.h>

#include "STD_MACROS.h"
#include "DIO.h"


#define PORT_8MODE 'A'
#define PORT_4MODE 'A'
#define RSPORT 'C'
#define RSPIN 1
#define RWPORT 'C'
#define RWPIN 2
#define EPORT 'C'
#define EPIN 3


#define EIGHT_BIT_MODE 



#define EIGHT_BIT_COM 0x38
#define CLRCOM 0x01
#define FIRST_ROW_COM 0x80
#define SECOND_ROW_COM 0xC0
#define DISPLAYON_CURSORON_COM 0X0E
#define DISPLAYON_CURSOROFF_COM 0X0C
#define DISPLAYON_CURSORBLINK_COM 0X0F
#define DISPLAYOFF_CURSORON_COM 0X0A
#define DISPLAYOFF_CURSOROFF_COM 0X08
#define MOVE_2RIGHT_COM 0X06
#define MOVE_2LEFT_COM 0X04
#define MOVE_CURSOR2LEFT_COM 0X10
#define MOVE_CURSOR2RIGHT_COM 0X14
#define RETURN_HOME 0X02
#define FOUR_BIT_COM 0X28
#define SHIFT_2LEFT_COM 0X07
#define SHIFT_2RIGHT_COM 0X05
#define SHIFT_DISPLAY2LEFT_COM 0X18
#define SHIFT_DISPLAY2RIGHT_COM 0X1C
#define CGROM_COM 0x40

static void Enable(void){
	DIO_voidWritePin(EPORT,EPIN,HIGH);
	_delay_ms(2);
	DIO_voidWritePin(EPORT,EPIN,LOW);
	_delay_ms(2);
}
void LCD_vInit(void){
	DIO_voidSetPortDir(PORT_8MODE,0XFF);
	DIO_voidSetPinDir(RSPORT,RSPIN,OUTPUT_PIN);
	DIO_voidSetPinDir(RWPORT,RWPIN,OUTPUT_PIN);
	DIO_voidSetPinDir(EPORT,EPIN,OUTPUT_PIN);
	
	#ifdef EIGHT_BIT_MODE
	LCD_vSendCmd(EIGHT_BIT_COM);
	#else
	LCD_vSendCmd(RETURN_HOME);
	LCD_vSendCmd(FOUR_BIT_COM);
	#endif
	
	LCD_vSendCmd(CLRCOM);
	LCD_vSendCmd(DISPLAYON_CURSOROFF_COM);
	LCD_vSendCmd(MOVE_2RIGHT_COM);
	
	
}
void LCD_vSendCmd(uint8 command){
	DIO_voidWritePin(RWPORT,RWPIN,LOW);
	#ifdef EIGHT_BIT_MODE
	DIO_voidWritePort(PORT_8MODE,command);
	DIO_voidWritePin(RSPORT,RSPIN,LOW);
	Enable();
	_delay_ms(1);
	#else
	DIO_voidWriteNibble(PORT_4MODE,command>>4,LAST4);
	DIO_voidWritePin(RSPORT,RSPIN,LOW);
	Enable();
	DIO_voidWriteNibble(PORT_4MODE,command,LAST4);
	Enable();
	#endif
	
}
void LCD_vSendData(uint8 data){
	DIO_voidWritePin(RWPORT,RWPIN,LOW);
	#ifdef EIGHT_BIT_MODE
	DIO_voidWritePort(PORT_8MODE,data);
	DIO_voidWritePin(RSPORT,RSPIN,HIGH);
	Enable();
	#else
	DIO_voidWriteNibble(PORT_4MODE,data>>4,LAST4);
	DIO_voidWritePin(RSPORT,RSPIN,HIGH);
	Enable();
	DIO_voidWriteNibble(PORT_4MODE,data,LAST4);
	Enable();
	#endif
}
void LCD_vCLR(void){
	LCD_vSendCmd(CLRCOM);
	_delay_ms(10);
}
void LCD_vSendString(uint8* ptr){
	while(*ptr!=0){
		LCD_vSendData(*ptr);
		ptr++;
	}
}
void LCD_vMoveCursor(uint8 row ,uint8 column){
	uint8 data;
	if((row>2)||(row<1)||(column<1)||(column>16)){
		data=FIRST_ROW_COM;
	}
	else if(row==1){
		data=FIRST_ROW_COM+column-1;
	}
	else if(row==2){
		data=SECOND_ROW_COM+column-1;
	}
	else{
		
	}
	LCD_vSendCmd(data);
}
