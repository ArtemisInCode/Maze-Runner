#ifndef MOVEMENT_H
#define MOVEMENT_H

// #include "system.h"
// #include "pio.h"
#include "pacer.h"
#include <stdint.h>
// #include <stdlib.h>
#include <stdbool.h>

#define PACER_RATE 500;


/* Checks whether player move is legal */
bool isLegalMove (uint16_t map, uint16_t player_X, uint16_t player_Y);

/* Updates and displays the new map using coords */
void updateMap(uint16_t map, uint16_t player_X, uint16_t player_Y);

/* Allows the player to navigate around the map */
void navigation (uint16_t map, Stats_t *levelStats);

#endif //MOVEMENT_H