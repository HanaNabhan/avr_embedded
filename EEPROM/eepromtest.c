/*
 * write_to_specific_address_on_EEPROM.c
 *
 * Created: 8/24/2018 6:42:56 AM
 *  Author: Mohamed Zaghlol
 */ 


#include "EEPROM_driver.h"
int main(void)
{
	
	EEPROM_write(0x0030,0X50);
    while(1)
    {
        
    }
}