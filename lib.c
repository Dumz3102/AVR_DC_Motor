#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "lib.h"

void PWM_Init(uint16_t period)
{
	DDRD = 0xFF; // PORT D is output
	TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
	// Fast PWM Mode, no - prescaler, ICR1 top ,Clear OCR pin on Compare Match
	// CS12 = CS11 = 0; CS10 = 1(setup trong ham start)
	ICR1 = period;   // F_CPU = 8Mhz -> T_CPU = 1/8M = 0.125us
	// T = period * 0.125us
}

void PWM_Start(void)
{
	TCCR1B |= (1 << CS10);
}

void Tien(uint16_t duty)
{
	PORTD |= (1 << IN1);
	PORTD &= ~(1 << IN2);
	PORTD |= (1 << IN3);
	PORTD &= ~(1 << IN4);
	OCR1B = duty;
	OCR1A = duty;
	PWM_Start();
}

void Lui(uint16_t duty)
{
	PORTD |= (1 << IN2);
	PORTD &= ~(1 << IN1);
	PORTD |= (1 << IN4);
	PORTD &= ~(1 << IN3);
	OCR1B = duty;
	OCR1A = duty;
	PWM_Start();
}

void Trai(uint16_t duty)
{
	OCR1B = duty;
	OCR1A = 0;
	PWM_Start();
}

void Phai(uint16_t duty)
{
	OCR1A = duty;
	OCR1B = 0;
	PWM_Start();
}

void Dung(uint16_t duty)
{
	PORTD  &= ~(1 << IN1);
	PORTD  &= ~(1 << IN2);
	PORTD  &= ~(1 << IN3);
	PORTD  &= ~(1 << IN4);
	TCCR1B &= ~(1 << CS10);
}
