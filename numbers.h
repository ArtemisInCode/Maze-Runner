/** @file	numbers.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Contains all structures to be initialised for gameplay
*/

#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdint.h>

void printNumbers(uint8_t number[], int8_t step);
uint8_t* createNumber(uint16_t number, uint8_t* numLen);

#endif
