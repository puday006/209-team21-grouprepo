/*
 * UART.c
 *
 * Created: 11/08/2026 1:41:06 PM
 * Author : kman371
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <stdint.h>
#include "UART.h"

#define UBRR_VALUE  12

#define PRIMES_LEN 62

#define STAGE 3 /*determines which part of the lab runs (4.5,4.6,4.7) */

bool is_prime(uint16_t v) {
	if (v < 2) return false;
	for (uint16_t i = 2; i < v; i++) {
		if (v % i == 0) return false;
	}
	return true;
}

int main(void) {
	usart_init(12);

	#if STAGE == 1
	/* Q4.5: send '3' every 0.5s */
	while (1) {
		usart_transmit('3');
		_delay_ms(500);
	}

	#elif STAGE == 2
	/* Q4.6: send "345" every 0.5s */
	while (1) {
		uint16_t number = 345;
		usart_transmit((number / 100) % 10 + '0');
		usart_transmit((number / 10)  % 10 + '0');
		usart_transmit( number        % 10 + '0');
		usart_transmit(' ');
		_delay_ms(500);
	}

	#elif STAGE == 3
	/* Q4.7: send the full primes list */
	uint16_t primes[PRIMES_LEN];
	uint8_t  count = 0;

	for (uint16_t n = 2; n <= 300 && count < PRIMES_LEN; n++) {
		if (is_prime(n)) {
			primes[count] = n;
			count++;
		}
	}

	while (1) {
		for (uint8_t i = 0; i < PRIMES_LEN; i++) {
			uint16_t num = primes[i];

			usart_transmit((num / 100) % 10 + '0');
			usart_transmit((num / 10)  % 10 + '0');
			usart_transmit( num        % 10 + '0');

			usart_transmit(',');
			usart_transmit(' ');
		}
		_delay_ms(2000);
	}
	#endif
}

