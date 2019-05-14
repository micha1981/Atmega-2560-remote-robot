/*
 * UART.c
 *
 *  Created on: 12.02.2017
 *      Author: Michal
 */
#include <avr/io.h>

#include "UART.h"

void USART_ON(){
UBRR2L = 51; // baud 19200
UBRR2H = 0;
UCSR2B |= (1 << RXEN2)|(1 << TXEN2)|(1<<RXCIE2); /* wlaczenie odbioru i nadawanie RXTX i przerywan*/
UCSR2C |= (1<<UCSZ21)|(1<<UCSZ20); /* odbior danych 8 bitowych*/
}

void ADC_ON(void){
ADMUX|= (1<<REFS0); // wewnetrzne napieie 5v wejscie ADC0
ADCSRA |= ( 1<<ADEN) |(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // 128 preskaler
}

int ADC_GET (void){
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADCW;
}
void USART_SENT(char znak)
{ while(!(UCSR2A & (1<<UDRE2)));
  UDR2=znak;
}

void uart_puts(char *s)		// wysy³a ³añcuch z pamiêci RAM na UART
{
  register char c;
  while ((c = *s++)) USART_SENT(c);			// dopóki nie napotkasz 0 wysy³aj znak
}

void uart_putint(int value)	// wysy³a na port szeregowy tekst
{
	char string[12];			// bufor na wynik funkcji itoa
	itoa(value, string,10);		// konwersja value na ASCII
	uart_puts(string);			// wyœlij string na port szeregowy
}



void USART_OFF(){
	 UCSR2B &=~(1 << RXEN2)|~(1 << TXEN2); /* wylaczenie odbioru i nadawanie RXTX */
}




int USART_GET(void)
{ while(!(UCSR2A & (1<<RXC2)));
  return UDR2;
}

void GO(){
	PORTK&=~(1<<PK3);
	PORTK&=~(1<<PK4);
	OCR0A =220;
	OCR0B =225;
}

void BACK(){
	PORTK |=(1<<PK3);
	PORTK |=(1<<PK4);
	OCR0A =200;
	OCR0B =210;

}

void STOP(){
	OCR0A =0;
	OCR0B =0;
	PORTK&=~(1<<PK3);
	PORTK&=~(1<<PK4);
}

void RIGHT(){

	PORTK|=(1<<PK3);
	PORTK&=~(1<<PK4);
	OCR0A =200;
	OCR0B =200;
}

void LEFT(){

	PORTK|=(1<<PK4);
	PORTK&=~(1<<PK3);
	OCR0A =200;
	OCR0B =200;
}

void PWM_ENABLE(){
		DDRB |= (1 << PB7);
		DDRG |= (1 << PG5);
		// PB7 PB6 jest wyjsciem




		TCCR0A |= (1 << COM0A1) | (1 << COM0B1);


		// set none-inverting mode

		TCCR0A |= (1 << WGM01) | (1 << WGM00);
		// set fast PWM Mode

		TCCR0B |= (1 << CS01);

		// set prescaler to 8 and starts PWM




}




