/*
 * EVM.c
 *
 * Created: 7/28/2024 1:11:08 PM
 *  Author: Hana Nabhan
 */ 


#include <avr/io.h>
#include <util/delay.h>

#include "STD_MACROS.h"
#include "BUTTON.h"
#include "LCD.h"
#include  "DIO.h"

#define F_CPU 8000000UL
#define button1PORT 'D'
#define button2PORT 'D'
#define button3PORT 'D'
#define button4PORT 'D'
#define button5PORT 'D'

#define button1PIN 3
#define button2PIN 4
#define button3PIN 5
#define button4PIN 6
#define button5PIN 7


int main(void)
{
	LCD_vInit();
	BUTTON_voidINIT(button1PORT,button1PIN);
	BUTTON_voidINIT(button2PORT,button2PIN);
	BUTTON_voidINIT(button3PORT,button3PIN);
	BUTTON_voidINIT(button4PORT,button4PIN);
	BUTTON_voidINIT(button5PORT,button5PIN);
	LCD_vMoveCursor(1,4);
	LCD_vSendString("WELCOME TO");
	LCD_vMoveCursor(2,7);
	LCD_vSendString(" EVM!");
	_delay_ms(1000);
	LCD_vCLR();
	LCD_vMoveCursor(1,1);
	LCD_vSendString("A=0");
	LCD_vMoveCursor(1,12);
	LCD_vSendString("B=0");
	LCD_vMoveCursor(2,1);
	LCD_vSendString("C=0");
	LCD_vMoveCursor(2,12);
	LCD_vSendString("D=0");
	
	uint8 c1=0,c2=0,c3=0,c4=0;
    while(1)
    {

		if(1==BUTTON_u8Read(button1PORT,button1PIN))
		{
			c1++;
			LCD_vMoveCursor(1,3);
			if(c1<10){
				LCD_vSendData(c1+48);
			}
			else if(c1<100){
				LCD_vSendData(c1/10+48);
				LCD_vSendData(c1%10+48);
			}
			 else if(c1<1000){
				 LCD_vSendData(c1/100+48);
				 LCD_vSendData((c1%100)/10+48);
				 LCD_vSendData((c1%100)%10+48);
			 }
			
        
         }
		 if(1==BUTTON_u8Read(button2PORT,button2PIN))
		 {
			  c2++;
			 LCD_vMoveCursor(1,14);
			 if(c2<10){
				 LCD_vSendData(c2+48);
			 }
			 else if(c2<100){
				 LCD_vSendData(c2/10+48);
				 LCD_vSendData(c2%10+48);
			 }
			 else if(c2<1000){
				 LCD_vSendData(c2/100+48);
				 LCD_vSendData((c2%100)/10+48);
				 LCD_vSendData((c2%100)%10+48);
			 }
			 
			
			 
		 }
		 if(1==BUTTON_u8Read(button3PORT,button3PIN))
		 {
			 c3++;
			 LCD_vMoveCursor(2,3);
			 if(c3<10){
			 LCD_vSendData(c3+48);
			 }
			 else if(c3<100){
				 LCD_vSendData(c3/10+48);
				 LCD_vSendData(c3%10+48);
			 }			 
			  else if(c3<1000){
				  LCD_vSendData(c3/100+48);
				  LCD_vSendData((c3%100)/10+48);
				  LCD_vSendData((c3%100)%10+48);
			  }
			 
		 }
		 if(1==BUTTON_u8Read(button4PORT,button4PIN))
		 {
			 c4++;
			 LCD_vMoveCursor(2,14);
			if(c4<10){
				LCD_vSendData(c4+48);
			}
			else if(c4<100){
				LCD_vSendData(c4/10+48);
				LCD_vSendData(c4%10+48);
			}
			 else if(c4<1000){
				 LCD_vSendData(c4/100+48);
				 LCD_vSendData((c4%100)/10+48);
				 LCD_vSendData((c4%100)%10+48);
			 }
			
			 
		 }
		 if (1==BUTTON_u8Read(button5PORT,button5PIN))
		 {
			 //reset
			 c1=0;
			 c2=0;
			 c3=0;
			 c4=0;
			 LCD_vCLR();
			 LCD_vMoveCursor(1,1);
			 LCD_vSendString("A=0");
			 LCD_vMoveCursor(1,12);
			 LCD_vSendString("B=0");
			 LCD_vMoveCursor(2,1);
			 LCD_vSendString("C=0");
			 LCD_vMoveCursor(2,12);
			 LCD_vSendString("D=0");
		 }
		 _delay_ms(200);
		 
}
}