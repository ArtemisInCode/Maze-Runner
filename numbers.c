/** @file	numbers.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Creates and displays scrolling numbers 
*/
#include "ledmat.h"
#include "pacer.h"
#include <stdint.h>

#define PACER_RATE 500

void printNumbers(uint8_t number[], int8_t step)
{

			for(uint8_t i = 0; i<5; i++) { //write to each display columnn
				pacer_wait(); //allow for physical switching time
				if(i+step > 19 || i+step < 0) { //while in array bounds print number columns, 0x00 otherwise
					ledmat_display_column(0x00, i);
				} else {
					ledmat_display_column(number[i+step], i);
				}
			}
		
		

}

uint8_t* createNumber(uint16_t number, uint8_t* numLen)
{
	static uint8_t outputNumberArray[20];
	
	/*Array of bitmaps of all numbers 0 to 9*/
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
		
	uint8_t count = 5; //start position for scrolling
	
	for(uint8_t i = 0; i<20; i++) { //clears output
		outputNumberArray[i] = 0x00;
	}
	
	/*Splits number into digits and creates display bitmap*/
	while(number>0) {
	
		uint16_t mod = number % 10; //takes first digit of number
		
		count--;
		/*Adds zero column to front and adds columns of digit*/
		outputNumberArray[count*4] = 0x00;
		for(uint8_t i = ((count*4)+1); i<((count*4)+4); i++) {
			outputNumberArray[i] = numberArray[mod][(i-((count*4)+1))];
		}
		
		number = number/10; //removes first digit from number
		
	
	
	}
	
	*numLen = 5-count; //writes amount of numbers to be printed
	return outputNumberArray; //returns bitmap to be diplayed
}
