/*
 * UART.h
 *
 *  Created on: 12.02.2017
 *      Author: Michal
 */

#ifndef UART_H_
#define UART_H_
void PWM_ENABLE(void);
void USART_ON(void);
void USART_OFF(void);
void USART_SENT(char znak);
int USART_GET(void);
void ADC_ON(void);
int ADC_GET (void);
void uart_puts(char *s);
void uart_putint(int value);
void GO(void);
void STOP(void);
void LEFT(void);
void RIGHT(void);
void BACK(void);
#endif /* UART_H_ */
