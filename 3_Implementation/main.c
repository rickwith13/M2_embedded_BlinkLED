#ifndef __AVR_ATmega328__
	#define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL // 16MHz

#include <avr/io.h>

#include <util/delay.h>

#include <avr/interrupt.h>

 

uint16_t rising, falling;

volatile uint32_t counts; //it protects the compiler from changing the value of the variable

volatile uint32_t dist;

uint16_t us_per_count; //this is the measurement cycle

 

 

 

ISR(TIMER1_CAPT_vect)

{

if(TCCR1B & (1<<ICES1)) // trigger capture of rising edge

{

rising = ICR1; // Save to Input Capture Register

    TCCR1B &= ~(1<<ICES1); //detect the falling edge

}

else 

{

falling = ICR1;

TCCR1B |= (1<<ICES1); //capture the falling edge time

counts = (uint32_t)falling - (uint32_t)rising ;

dist = (uint32_t)us_per_count * counts / 58;  //microseconds

}

}

ISR(TIMER1_COMPA_vect)

{

PORTB |= 1<<PINB2; //set the pin to high

_delay_us(10); //and then a delay of 10uS

PORTB &= ~(1<<PINB2); // set the pin to low and now comes the sonic burst from module

}

void init_timer()

{

TCCR1B |= (1<<WGM12);

TCCR1B |= (1<<CS11); // 

TIMSK1 |= (1<<ICIE1) | (1<<OCIE1A); // This is to enable the interrupt

TCCR1B |= 1 << ICES1;

OCR1A = 8750;

us_per_count = 8;

//OCR1A = (F_CPU/(8*2*freq) - 1); // this is to setup the output compare register to what we want

sei(); //this enables the interrupt to work

//us_per_count = 8;

}

int main(void)

{

    /* Replace with your application code */

DDRB |= 1 << DDB2;

DDRB |= (1<<DDB4); // for the LED

PORTB &= ~(1 << PINB2);

init_timer();

    while (1) 

    {

if (dist > 30)

{

PORTB |= (1<<PINB4);

if (dist < 30)

{

PORTB &= ~(1<<PINB4);

}

}

}

}
