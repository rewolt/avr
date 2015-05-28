/*
 * blinking.c
 *
 * Created: 2015-05-09 12:58:52
 *  Author: Admin
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define wait(czas) for(int i=0;i<(czas);i++) _delay_ms(1);

int main(void)
{
	DDRB = (1<<PB1);
	DDRB = (1<<PB0);
	DDRD = (1<<PD7);
	
    while(1)
    {	
        wait(950);
		PORTB &= ~(1<<PB0); //ustaw stan niski na wejœciu - zapalenie diody
		PORTD ^= (1<<PD7); // zmieñ stan patrz¹c na poprzedni, jaki by³
		wait(50);
		PORTB |= (1<<PB0); //ustaw stan wysoki na wejœciu - zgaszenie diody
    }
}