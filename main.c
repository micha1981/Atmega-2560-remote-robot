
#include <avr/io.h>
#include "UART.h"
#include <avr/interrupt.h>
#include <util/delay.h>
volatile char uart_get;

ISR (USART2_RX_vect){
uart_get=USART_GET();
if(uart_get=='d') RIGHT();
if(uart_get=='a') LEFT();
if(uart_get=='w') GO();
if(uart_get=='s') STOP();
if(uart_get=='e') BACK();
USART_SENT(uart_get);
}

int main (void){
USART_ON();
sei();
//ADC_ON();
PWM_ENABLE();


DDRK|=(1<<PK3);
DDRK|=(1<<PK4);

while(1)
{

}
}



