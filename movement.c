/** @file   movement.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Player movement for gameplay
*/

#include "movement.h"

bool is_legal_move(uint16_t map[], uint16_t player_X, uint16_t player_Y)
{
    bool isLegal = !((map[player_X]) & (1<<player_Y)); // Checks if the 'future' player position is '1' on the map. If 1, the move is legal

    return isLegal;
}

void collectable_pickup(Stats_t* stats, uint16_t collectables[]) 
{		
	bool isCollect = ((collectables[stats->X]) & (1<<(stats->Y))); // Checks if the player position is '1' on the map. If 1, there is a collectable

	if(isCollect) {
		stats->remainingCollectables--; // Removes one collectable from remaining collectables
		(collectables[stats->X]) &= ~(1<<(stats->Y)); // Removes the collectable from the map
	}
}

void update_map(uint16_t collectables[], uint16_t map[], uint16_t player_X, uint16_t player_Y)
{
    uint8_t col = 0; //zeros column value
    for(uint8_t i = (0 + player_X); i<(5 + player_X); i++) { // Moves accross 5 columns of bitmap to be displayed
        if(i-2 >= 0 && i-2 <= 19 ) { // If within bounds of bitmap array
            if(player_Y <= 3) { // If player futher left Y=3 shift direction is reversed to make top right X=0 Y=0 
                col = ((map)[i-2] << (3 - player_Y)) | ((collectables)[i-2] << (3 - player_Y)); // Sets column to be displayed 
            } else {
                col = ((map)[i-2] >> (player_Y - 3)) | ((collectables)[i-2] >> (player_Y - 3)); // Sets column to be displayed 
            }
            ledmat_display_column(col, i-player_X); // Displays column
        } else {
            ledmat_display_column(0x00, i-player_X); // Displays blank column
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
}
