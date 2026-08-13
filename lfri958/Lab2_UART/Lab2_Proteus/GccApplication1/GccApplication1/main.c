/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 4:27:09 PM
 * Author : kman371
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>


int main(void)
{	
	uint16_t primes[62];
	uint8_t count = 0;
	
	for (uint16_t i = 2; i <= 300; i++)
	{
		bool isprime = true;
		
		for (uint16_t j=2; j < i; j++)
		{
			if(i%j == 0){
				isprime = false;
				break;
			}
		}
		if (isprime)
		{
			primes[count]=i;
			count++;
		}
	}
    while (1) 
    {
    }
}

+-***************************************************