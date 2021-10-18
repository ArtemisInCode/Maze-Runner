/** @file	main.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  The main file for playing the UC4FK game
*/

#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"
#include "numbers.h"
#include "movement.h"
#include "ledHeader.h"

#define PACER_RATE 500 //game loop frequency (Hz)
#define NUMBER_STEP_START 13 //initial step position for single number
/*number of cycles between runs*/
#define MAP_TIMER_RATE 2
#define MOVEMENT_TIMER_RATE 10
#define COLLECTABLE_TIMER_RATE 50
#define NUMBER_TIMER_RATE 50

int main (void)
{

	/*initilisation fucntions to setup game*/
	header_init();
    system_init ();
    ledmat_init();
    pacer_init(PACER_RATE);;
    Map_collectables_t collectables = collectables_init();
    Stats_t stats = level_init(map_get(1), collectables.map1);
    
    uint8_t level = 1; //current game level
    uint8_t game_state = 0; //0-Running, 1-EndScreen, 2-Reset 3-Interlevel
    
	/*variables for counting cycles*/
    uint8_t map_timer = 0; //for updating the map display
    uint8_t movement_timer = 0; //for updating movement
    uint16_t collectable_timer = 0; //for updating collectable flashing
    uint16_t number_timer = 0; //for updating number scrolling
    uint16_t timer = 0; //for incrementing the score
    
    uint8_t numLen = 0; //length of string to print
    int8_t step = 21; //current print scrolling position
    uint8_t* numArray; //array of numbers to be printed
    uint16_t score = 0; //final time
	uint16_t levelNumber = 1; //game level for printing

    
    

	//prints text 1;
	step = NUMBER_STEP_START; 
	game_state = 3;
    while (1)
    {
    	pacer_wait();
    	switch(game_state) {
    	
    	case 0: //Running
			if(stats.remainingCollectables == 0) { //updates map when no collectables left
				level = (level + 1) % 3; //increments level
				switch(level) {
					case 1: //reset game
						game_state = 1;
						levelNumber = 1;
						stats = level_init(map_get(1), collectables.map1);
						break;
					case 2: //move to level 2
						levelNumber = 2;
						step = NUMBER_STEP_START;
						game_state = 3;
						stats = level_init(map_get(2), collectables.map2);
						break;
					case 0: //move to level 3
						levelNumber = 3;
						step = NUMBER_STEP_START;
						game_state = 3;
						stats = level_init(map_get(3), collectables.map3);
						break;
					default:
						continue;
				}
			}
		
			
			if(map_timer >= MAP_TIMER_RATE) { //displays the map and collectables for current player position
				if(collectable_timer < COLLECTABLE_TIMER_RATE) { //flashes collectables (ON)
					update_map(stats.collectables, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else if(collectable_timer < (COLLECTABLE_TIMER_RATE*2)) { //flashes collectables (OFF)
					update_map(collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else {
					collectable_timer = 0;
					update_map(collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				}			
			}
			
			/*increments timers*/
			map_timer ++;
			movement_timer ++;
			collectable_timer ++;
			timer++;
		
			if(movement_timer >= MOVEMENT_TIMER_RATE) { //updates postion from navstick input
				movement_update(stats.level, &stats);
				collectable_pickup(&stats, stats.collectables);
				header_set(stats.remainingCollectables);
				movement_timer = 0;
			}
			
			
			if(timer >= PACER_RATE/10) { //increments score
				timer = 0;
				score ++;	
			}
			
			ledmat_display_column(0x08, 2); //displays player in centre
			break;
		
		case 1: //EndScreen

			numArray = createNumber(score, &numLen); //generates bitmap for displaying score
			
			if(number_timer >= NUMBER_TIMER_RATE) { //scrolls score
				step ++;
				number_timer = 0;
			}
			if(step >= 21) { //resets scrolling
				step = 20 - (numLen*4) - 3;
			}
	 
			printNumbers(numArray, step); //displays score
			number_timer ++;
			
			navswitch_update ();
			if(navswitch_push_event_p(NAVSWITCH_PUSH)) { //resets game on navswitch push
				game_state = 2;
			}
			break;
		
		case 2: //Reset
			/*reverts game state to restart game*/
			stats = level_init(map_get(1), collectables.map1);
			level = 1;
			score = 0;
    		timer = 0;
    		levelNumber = 1;
    		step = NUMBER_STEP_START;
			game_state = 3;
			
			break;
		
		case 3: //Interlevel			
			
			numArray = createNumber(levelNumber, &numLen); //generates bitmap to display level number
			
			if(number_timer >= NUMBER_TIMER_RATE) { //scrolls level number
				step ++;
				number_timer = 0;
			}
			if(step >= 21) { //starts next level at end of scroll
				game_state = 0;
			}
	 
			printNumbers(numArray, step); //displays level number
			number_timer ++;
			
			break;
			
				
		}
	}
}
