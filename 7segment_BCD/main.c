



#include<avr/io.h>
#include<util/delay.h>
#include "STD_MACROS.h"
int main(){
	uint8 i;
	SevenSegment_voidInitBCD('D',0);

    while(1){
    	for(i=0;i<=9;i++){
    		SevenSegment_voidWriteBCD('D' ,i,0);
    		_delay_ms(1000);
    	}
    }

}
