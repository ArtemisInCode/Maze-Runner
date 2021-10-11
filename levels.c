#include <stdint.h>
// #include <stdlib.h>
#include "ledmat.h"
#include "levels.h"
#include "movement.h"
#include "collectables.h"
#include "maps.h"

// #include "system.h"
// #include "pio.h"
// #include "pacer.h"


Stats_t level_init(uint8_t level)
{
    Maps_t maps = maps_init();
    Map_collectables_t collectables = collectables_init();

    // Initialise level statistics
    Stats_t levelStats;
    levelStats.level = level;
    levelStats.isComplete = false;
    // TODO Fix this level_statisics.map = maps.map // TODO: select uint16_t map from maps using level
    // TODO levelStats.collectables = the specific struct for the level
    levelStats.numCollects = 0;
    levelStats.X = 2; // Coords start from top left corner (0,0)
    levelStats.Y = 13;
    levelStats.playerHP = 2;
    levelStats.bossHP = 6;
    
    return levelStats;
}


void play_level(uint16_t map, Stats_t *levelStats) 
{
    
    while (1)
    {

        ledmat_display_column(1, 2);
        // Some sort of animation to indicate level start - just the level number displayed for a bit?

        // navigation
        //navigation (map, &levelStats); // idk, this needs to pass the pointer so it can be edited in lower levels

        // scoring

        // next level - switch in main?

        //what happens if you die
    }
    
}