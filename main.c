#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"
#include "levels.h"
#include "scoring.h"
#include "messages.h"

#define PACER_RATE 500

int main (void)
{
//     // Initialisation
//     Maps_t maps = maps_init(); //Initialises all three level maps
//     Map_collectables_t collectables = collectables_init(); // Initialises the maps for collectables
    
//     while (1) {  

//         Score_t score = score_init();
//         Stats_t level1Stats = level_init(1);
//         Stats_t level2Stats = level_init(2);
//         Stats_t level3Stats = level_init(3);  
//         printText("Start!");

//         // Gameplay

//         // Play level 1
//         printText("1");
//         play_level(*maps.map1, &level1Stats);

//         // Check if dead
//         if (level1Stats.isComplete) {
//             // Play level 2
//             printText("2");
//             play_level(*maps.map2, &level2Stats);
//         } else {
//             gameEnd(&score, level1Stats);
//         }

//         if (level2Stats.isComplete) {
//             // Play level 3
//             printText("3");
//             play_level(*maps.map3, &level3Stats);
//         } else {
//             gameEnd(&score, level2Stats);
//         }
//         gameEnd(&score, level3Stats);
//     }
// }
    system_init ();
    ledmat_init();
    pacer_init(PACER_RATE);
    maps_t maps = maps_init();
    Stats_t stats = level_init(1);
    
    uint8_t map_timer = 0;
    uint8_t movement_timer = 0;
    
    


    while (1)
    {
    	pacer_wait();
		if(map_timer >=2) {
			update_map(maps.map1, stats.X, stats.Y);
			map_timer = 0;			
		}
		
		map_timer ++;
		movement_timer ++;
	
		if(movement_timer >= 10) {
			movement_update(maps.map1, &stats);
			movement_timer = 0;
		}
		
		ledmat_display_column(0x08, 2);
		
		
	

			
		}
}
