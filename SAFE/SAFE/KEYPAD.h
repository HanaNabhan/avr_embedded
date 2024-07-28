/*
 * KEYPAD.h
 *
 * Created: 7/18/2024 10:31:07 PM
 *  Author: Hana Nabhan
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define NOTPRESSED 0xFF

void KEYPAD_vInit(void);
uint8 KEYPAD_u8Read(void);


#endif /* KEYPAD_H_ */