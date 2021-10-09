#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include "movement.h"
#include "navswitch.h"
#include "levels.h"
//TODO: #include "maps.h"


Stats_t level_init(uint8_t level)
{
    maps_t maps = maps_init();

    // Initialise level statistics
    Stats_t level_statisics;
    // TODO Fix this level_statisics.map = maps.map
    level_statisics.X = 3;
    level_statisics.Y = 3;
    level_statisics.playerHP = 2;
    level_statisics.bossHP = 6;
    
    // TODO: select uint16_t map from maps using level
}


void play_level(maps_t maps) 
{
    
    while (1)
    {
        navigation (map, player_X, player_Y);
    }
    
}