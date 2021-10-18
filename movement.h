/** @file   movement.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Player movement for gameplay
*/


#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "ledmat.h"
#include "world.h"




/* Checks whether player move is legal */
bool is_legal_move (uint16_t map[], uint16_t player_X, uint16_t player_Y);

/* Updates and displays the new map using coords */
void update_map(uint16_t collectables[], uint16_t map[], uint16_t player_X, uint16_t player_Y);

/* Allows the player to navigate around the map */
void movement_update(uint16_t map[], Stats_t* levelStats);

/* 'Picks up' collectable when player moves over it - collision detection for collectables */
void collectable_pickup(Stats_t* stats, uint16_t collectables[]);

#endif //MOVEMENT_H
