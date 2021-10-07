#ifndef LEDHEADER_H
#define LEDHEADER_H

#include <avr/io.h>
#include "system.h"


void header_init(void); // Initilises header for leds
void header_set(uint8_t amount); //Sets number of leds on

#endif
