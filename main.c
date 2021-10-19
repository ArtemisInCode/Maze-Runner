/** @file	main.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  The main file for playing the UC4FK game
*/

#include <avr/io.h>

#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"

#include "world.h"
#include "numbers.h"
#include "movement.h"
#include "ledHeader.h"

#define PACER_RATE 500 // Game loop frequency (Hz)
#define NUMBER_STEP_START 13 // Initial step position for single number

/* Number of cycles between runs */
#define MAP_TIMER_RATE 2
#define MOVEMENT_TIMER_RATE 10
#define COLLECTABLE_TIMER_RATE 50
#define NUMBER_TIMER_RATE 50

#define MAX_NUMBER_LENGTH 20

int main (void)
{
	/* Initilisation fucntions to setup game */
	header_init ();
    system_init ();
    ledmat_init ();
    pacer_init (PACER_RATE);;
    Map_collectables_t collectables = collectables_init (); // Collectable maps
    Stats_t stats = level_init (map_get (1), collectables.map1); // Level statistics
    
	uint8_t level = 1; // Current game level
    uint8_t game_state = 0; // 0-Running, 1-EndScreen, 2-Reset, 3-Interlevel
    
	/* Variables for counting cycles */
    uint8_t map_timer = 0; // For updating the map display
    uint8_t movement_timer = 0; // For updating movement
    uint16_t collectable_timer = 0; // For updating collectable flashing
    uint16_t number_timer = 0; // For updating number scrolling
    uint16_t timer = 0; // For incrementing the score
    
	/* For number scrolling */
    uint8_t num_len = 0; // Length of string to print
    int8_t step = MAX_NUMBER_LENGTH + 1; // Current print scrolling position
    uint8_t* num_array; // Array of numbers to be printed
    uint16_t score = 0; // Final time
	uint16_t level_number = 1; // Game level for printing
    
	/* Prints text 1 */
	step = NUMBER_STEP_START; 
	game_state = 3;


	/* Main game loop */
    while (1)
    {

    	pacer_wait();

		/* Game state switching */
    	switch (game_state) {
    	
    	case 0: // Running
			if (stats.remainingCollectables == 0) { // Updates map when there are no collectables left
				level = (level + 1) % 3; // Increments level
				switch (level) {
					case 1: // Reset game
						game_state = 1;
						level_number = 1;
						stats = level_init (map_get (1), collectables.map1);
						break;
					case 2: // Move to level 2
						level_number = 2;
						step = NUMBER_STEP_START;
						game_state = 3;
						stats = level_init (map_get (2), collectables.map2);
						break;
					case 0: // Move to level 3
						level_number = 3;
						step = NUMBER_STEP_START;
						game_state = 3;
						stats = level_init (map_get (3), collectables.map3);
						break;
					default:
						continue;
				}
			}
		
			if (map_timer >= MAP_TIMER_RATE) { // Displays the map and collectables for current player position
				if (collectable_timer < COLLECTABLE_TIMER_RATE) { // Flashes collectables (ON)
					update_map (stats.collectables, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else if (collectable_timer < (COLLECTABLE_TIMER_RATE*2)) { // Flashes collectables (OFF)
					update_map (collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else {
					collectable_timer = 0;
					update_map (collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				}			
			}
			
			/* Increments timers */
			map_timer ++;
			movement_timer ++;
			collectable_timer ++;
			timer ++;
		
			if (movement_timer >= MOVEMENT_TIMER_RATE) { // Updates postion from navstick input
				movement_update (stats.level, &stats);
				collectable_pickup (&stats, stats.collectables);
				header_set (stats.remainingCollectables);
				movement_timer = 0;
			}
			
			if (timer >= PACER_RATE/10) { // Increments score
				timer = 0;
				score ++;	
			}
			
			ledmat_display_column (0x08, 2); // Displays player in centre of screen
			break;
		
		case 1: // EndScreen
			num_array = create_number (score, &num_len); // Generates bitmap for displaying score
			
			if (number_timer >= NUMBER_TIMER_RATE) { // Scrolls score
				step ++;
				number_timer = 0;
			}
			if (step >= (MAX_NUMBER_LENGTH + 1)) { // Resets scrolling
				step = MAX_NUMBER_LENGTH - (num_len*4) - 3;
			}
	 
			print_numbers (num_array, step); // Displays score
			number_timer ++;
			
			navswitch_update ();
			if (navswitch_push_event_p(NAVSWITCH_PUSH)) { // Resets game on navswitch push
				game_state = 2;
			}
			break;
		
		case 2: // Reset
			/* Reverts game state to restart game */
			stats = level_init (map_get (1), collectables.map1);
			level = 1;
			score = 0;
    		timer = 0;
    		level_number = 1;
    		step = NUMBER_STEP_START;
			game_state = 3;
			
			break;
		
		case 3: // Interlevel			
			
			num_array = create_number (level_number, &num_len); // Generates bitmap to display level number
			
			if (number_timer >= NUMBER_TIMER_RATE) { // Scrolls level number
				step ++;
				number_timer = 0;
			}
			if (step >= (MAX_NUMBER_LENGTH + 1)) { // Starts next level at end of scroll
				game_state = 0;
			}
	 
			print_numbers (num_array, step); // Displays level number
			number_timer ++;
			
			break;	
		}
	}
}
