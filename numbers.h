/** @file	numbers.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Contains all structures to be initialised for gameplay
*/

#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdint.h>
/*prints to display at given position in given bitmap (number is uint8_t number[20])*/
void printNumbers(uint8_t number[], int8_t step);
/*generates bitmap to be printed by printNumbers from a number gives number length*/
uint8_t* createNumber(uint16_t number, uint8_t* numLen);

#endif
