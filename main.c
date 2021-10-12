// Header Files as necessary

#include <stdint.h>
#include <stdio.h>
#include "maps.h"
#include "levels.h"
#include "scoring.h"
#include "messages.h"

/* The main funct for playing the game */
int main(void)
{
    // Initialisation
    Maps_t maps = maps_init(); //Initialises all three level maps
    Map_collectables_t collectables = collectables_init(); // Initialises the maps for collectables
    
    while (1) {  

        Score_t score = score_init();
        Stats_t level1Stats = level_init(1);
        Stats_t level2Stats = level_init(2);
        Stats_t level3Stats = level_init(3);  
        printText("Start!");

        // Gameplay

        // Play level 1
        printText("1");
        play_level(*maps.map1, &level1Stats);

        // Check if dead
        if (level1Stats.isComplete) {
            // Play level 2
            printText("2");
            play_level(*maps.map2, &level2Stats);
        } else {
            gameEnd(&score, level1Stats);
        }

        if (level2Stats.isComplete) {
            // Play level 3
            printText("3");
            play_level(*maps.map3, &level3Stats);
        } else {
            gameEnd(&score, level2Stats);
        }
        gameEnd(&score, level3Stats);
    }
}