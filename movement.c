#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include "movement.h"
#include "navswitch.h"
#include <stdbool.h>
#include "ledmat.h"
#include "collectables.h"


bool isLegalMove (uint16_t map, uint16_t player_X, uint16_t player_Y)
{
    bool isLegal = true;
    // TODO: check whether move would go into a wall
    // Use map nums and check with bitshifting

    return isLegal;
}

void updateMap(uint16_t map, uint16_t player_X, uint16_t player_Y)
{
    // Updates the map using coords - return map
    for(uint8_t i = (0 + player_X); i<(5 + player_X); i++) {
				if(i-2 >= 0 && i-2 <= 19 ) {
					if(player_Y <= 3) {
						col = ((maps.map3)[i-2] << (3-player_Y));
					} else {
						col = ((maps.map3)[i-2] >> player_Y);
					}
					ledmat_display_column(col, i-player_X);
				} else {
					ledmat_display_column(0x00, i-player_X);
				}
}

void navigation (uint16_t map, Stats_t *levelStats)
{
    //TODO: use map select initial bitmap using player_X and player_Y coords
    updateMap(map, levelStats.X, levelStats.Y);

    // system_init ();
    // navswitch_init ();
    // pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait ();
        navswitch_update ();
        
        if ((navswitch_push_event_p (NAVSWITCH_NORTH)) && isLegalMove(map, levelStats.X, levelStats.Y-1)) {
            levelStats.Y --; // Change map NORTH
        }
        if ((navswitch_push_event_p (NAVSWITCH_EAST)) && isLegalMove(map, levelStats.X+1, levelStats.Y)) {
            levelStats.X ++; // Change map EAST
        }
        if ((navswitch_push_event_p (NAVSWITCH_SOUTH)) && isLegalMove(map, levelStats.X, levelStats.Y+1)) {
            levelStats.Y ++; // Change map SOUTH
        }
        if ((navswitch_push_event_p (NAVSWITCH_WEST)) && isLegalMove(map, levelStats.X-1, levelStats.Y)) {
            levelStats.X --; // Change map WEST
        }
        if (isCollectable(levelStats.level, levelStats.Y, levelStats.Y)) {
            levelStats.bossHP --;
            // take collectable off display and map??
        }
        
        updateMap(map, levelStats.X, levelStats.Y);
    }
    return 0;
}
