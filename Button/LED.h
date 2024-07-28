/*
 * LED.h
 *
 *
 *      Author: Hana Nabhan
 */

#ifndef LED_H_
#define LED_H_


void LED_voidINIT(uint8 port, uint8 pin);
void LED_voidON(uint8 port, uint8 pin);
void LED_voidOFF(uint8 port, uint8 pin);
void LED_voidToggle(uint8 port ,uint8 pin);
uint8 LED_u8ReadStatus(uint8 port ,uint8 pin);


#endif /* LED_H_ */
