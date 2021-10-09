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
    Stats_t level_stats;
    // TODO Fix this level_statisics.map = maps.map // TODO: select uint16_t map from maps using level
    level_stats.X = 3;
    level_stats.Y = 3;
    level_stats.playerHP = 2;
    level_stats.bossHP = 6;
    
    return level_stats;
}


void play_level(maps_t maps, Stats_t level_stats) 
{
    
    while (1)
    {
        // navigation
        navigation (map, level_stats);

        // scoring

        // next level

        //what happens if you die
    }
    
}