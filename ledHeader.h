/** @file	LedHeader.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Initialisation and set up of the external LEDs
*/

#ifndef LEDHEADER_H
#define LEDHEADER_H

#include <avr/io.h>
#include "system.h"


/* Initilises header for leds */
void header_init (void);

/* Sets number of leds on */
void header_set (uint8_t amount);

#endif //LEDHEADER_H
