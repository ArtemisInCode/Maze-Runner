#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include "movement.h"
#include "navswitch.h"
#include "levels.h"
#include "collectables.h"
#include "maps.h"


Stats_t level_init(uint8_t level)
{
    maps_t maps = maps_init();
    map_collectables_t collectables = collectables_init();

    // Initialise level statistics
    Stats_t levelStats;
    levelStats.level = level;
    // TODO Fix this level_statisics.map = maps.map // TODO: select uint16_t map from maps using level
    // TODO levelStats.collectables = the specific struct for the level
    levelStats.X = 2; // Coords start from top left corner (0,0)
    levelStats.Y = 13;
    levelStats.playerHP = 2;
    levelStats.bossHP = 6;
    
    return levelStats;
}


void play_level(maps_t maps, Stats_t levelStats) 
{
    
    while (1)
    {
        // Some sort of animation to indicate level start - just the level number displayed for a bit?

        // navigation
        navigation (map, &levelStats); // idk, this needs to pass the pointer so it can be edited in lower levels

        // scoring

        // next level - switch in main?

        //what happens if you die
    }
    
}