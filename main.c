// Header Files as necessary

#include <stdint.h>
#include <stdio.h>
#include "maps.h"
#include "levels.h"

/* The main funct for playing the game */
int main(void)
{
    // Initialisation here
    Maps_t maps = maps_init(); //Initialises all three level maps
    Map_collectables_t collectables = collectables_init(); // Initialises the maps for collectables
    Stats_t level1Stats = level_init(uint8_t 1);
    Stats_t level2Stats = level_init(uint8_t 2);
    Stats_t level3Stats = level_init(uint8_t 3);

    

    // Gameplay here

    // Play level 1
    play_level(maps.map1);

    // TODO: check if dead

    // Play level 2
    play_level(maps.map2);

    // TODO: check if dead

    // Play level 3
    play_level(maps.map3);

    

    // Ending and stats here
}