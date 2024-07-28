/*
 * LCD.c
 *
 * Created: 6/9/2023 12:10:12 AM
 *  Author: Hana Nabhan
 */

#ifndef LCD_H_
#define LCD_H_


static void Enable(void);
void LCD_vInit(void);
void LCD_vSendCmd(uint8 command);
void LCD_vSendData(uint8 data);
void LCD_vSendString(uint8* ptr);
void LCD_vCLR(void);
void LCD_vMoveCursor(uint8 row ,uint8 column);



#endif /* LCD_H_ */