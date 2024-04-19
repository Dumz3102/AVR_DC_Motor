#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "lib.h"

int main(void)
{
    // IO init
	DDRD  = 0xFF; // output
	DDRB  = 0x00;
	PORTB = 0xFF; // input pull up
	
	PWM_Init(chuky);
	
    while (1) 
    {
		if((PINB & (1 << 0)) == 0)
		{
			_delay_ms(1);
			while((PINB & (1 << 0)) == 0);
			Tien(dutyc);
		}
		if((PINB & (1 << 1)) == 0)
		{
			_delay_ms(1);
			while((PINB & (1 << 1)) == 0);
			Lui(dutyc);
		}
		if((PINB & (1 << 2)) == 0)
		{
			_delay_ms(1);
			while((PINB & (1 << 2)) == 0);
			Trai(dutyc);
		}
		if((PINB & (1 << 3)) == 0)
		{
			_delay_ms(1);
			while((PINB & (1 << 3)) == 0);
			Phai(dutyc);
		}
		if((PINB & (1 << 4)) == 0)
		{
			_delay_ms(1);
			while((PINB & (1 << 4)) == 0);
			Dung(dutyc);
		}
    }
}

