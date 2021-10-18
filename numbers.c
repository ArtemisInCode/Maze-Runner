/** @file	numbers.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Contains all structures to be initialised for gameplay
*/
#include "ledmat.h"
#include "pacer.h"
#include <stdint.h>

#define PACER_RATE 500

void printNumbers(uint8_t number[], int8_t step)
{

			for(uint8_t i = 0; i<5; i++) {
				pacer_wait();
				if(i+step > 19 || i+step < 0) {
					ledmat_display_column(0x00, i);
				} else {
					ledmat_display_column(number[i+step], i);
				}
			}
		
		

}

uint8_t* createNumber(uint16_t number, uint8_t* numLen)
{
	static uint8_t outputNumberArray[20];
	
	uint8_t numberArray[10][3] = {
		{0x3e, 0x22, 0x3e},
		{0x24, 0x3e, 0x20},
		{0x3a, 0x2a, 0x2e},
		{0x2a, 0x2a, 0x3e},
		{0x0e, 0x08, 0x3e},
		{0x2e, 0x2a, 0x3a},
		{0x3e, 0x2a, 0x3a},
		{0x02, 0x02, 0x3e},
		{0x3e, 0x2a, 0x3e},
		{0x0e, 0x0a, 0x3e}
		};
		
	uint8_t count = 5;
	
	for(uint8_t i = 0; i<20; i++) {
		outputNumberArray[i] = 0x00;
	}
	
	while(number>0) {
	
		uint16_t mod = number % 10;
		
		count--;
		outputNumberArray[count*4] = 0x00;
		for(uint8_t i = ((count*4)+1); i<((count*4)+4); i++) {
			outputNumberArray[i] = numberArray[mod][(i-((count*4)+1))];
		}
		
		number = number/10;
		
	
	
	}
	
	*numLen = 5-count;	
	return outputNumberArray;
}
