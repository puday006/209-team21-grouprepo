/*
 * UART.c
 *
 * Created: 11/08/2026 1:55:00 PM
 *  Author: kman371
 */ 

#include "UART.h"

void usart_init(uint16_t ubrr){
	UCSR0B = 0b00001000;
	UCSR0C = 0b00000110;
	UBRR0 = ubrr;      
}

void usart_transmit(uint8_t data){
	while ((UCSR0A & (1 << UDRE0)) == 0){
		;
	}
	UDR0 = data;
}