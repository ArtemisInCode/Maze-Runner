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
    Stats_t level1Stats = level_init(1);
    Stats_t level2Stats = level_init(2);
    Stats_t level3Stats = level_init(3);

    

    // Gameplay here

    // Play level 1
    play_level(*maps.map1, &level1Stats);

    // TODO: check if dead

    // Play level 2
    play_level(*maps.map2, &level2Stats);

    // TODO: check if dead

    // Play level 3
    play_level(*maps.map3, &level3Stats);

    

    // Ending and stats here
}