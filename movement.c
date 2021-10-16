#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "navswitch.h"
#include "ledmat.h"
#include "maps.h"
//#include "collectables.h"
#include "movement.h"

// #include "system.h"
// #include "pio.h"


bool is_legal_move(uint16_t map[], uint16_t player_X, uint16_t player_Y)
{
    // check whether move would go into a wall
    // Use map nums and check with bitshifting
    bool isLegal = !((map[player_X]) & (1<<player_Y));

    return isLegal;
}

void collectable_pickup(Stats_t* stats, uint16_t collectables[]) {
	
	
	bool isCollect = ((collectables[stats->X]) & (1<<(stats->Y)));
	if(isCollect) {
		stats->remainingCollectables--;
		(collectables[stats->X]) &= ~(1<<(stats->Y));
	}

}

void update_map(uint16_t collectables[], uint16_t map[], uint16_t player_X, uint16_t player_Y)
{
    // Updates the map using coords - dipalay map
    uint8_t col = 0;
    for(uint8_t i = (0 + player_X); i<(5 + player_X); i++) {
				if(i-2 >= 0 && i-2 <= 19 ) {
					if(player_Y <= 3) {
						col = ((map)[i-2] << (3 - player_Y)) | ((collectables)[i-2] << (3 - player_Y));
					} else {
						col = ((map)[i-2] >> (player_Y - 3)) | ((collectables)[i-2] >> (player_Y - 3));
					}
					ledmat_display_column(col, i-player_X);
				} else {
					ledmat_display_column(0x00, i-player_X);
				}
			}
}

void movement_update(uint16_t map[], Stats_t *levelStats)
{
	navswitch_update ();
    
    if ((navswitch_push_event_p (NAVSWITCH_NORTH)) && is_legal_move(map, levelStats->X, levelStats->Y-1)) {
		levelStats->Y --; // Change map NORTH
    }
        if ((navswitch_push_event_p (NAVSWITCH_EAST)) && is_legal_move(map, levelStats->X+1, levelStats->Y)) {
            levelStats->X ++; // Change map EAST
       }
        if ((navswitch_push_event_p (NAVSWITCH_SOUTH)) && is_legal_move(map, levelStats->X, levelStats->Y+1)) {
            levelStats->Y ++; // Change map SOUTH
        }
        if ((navswitch_push_event_p (NAVSWITCH_WEST)) && is_legal_move(map, levelStats->X-1, levelStats->Y)) {
            levelStats->X --; // Change map WEST
        }

        //if (isCollectable(levelStats->level, levelStats->X, levelStats->Y)) {
        //    levelStats->bossHP --;
            // take collectable off display and map??
        //}
        
        
}
