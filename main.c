/** @file	main.c
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  The main file for playing the UC4FK game
*/


// Several of these are almost certainly redundant

#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"
#include "numbers.h"

#define PACER_RATE 500

int main (void)
{
	
	header_init();
    system_init ();
    ledmat_init();
    pacer_init(PACER_RATE);;
    map_collectables_t collectables = collectables_init();
    Stats_t stats = level_init(map_get(1), collectables.map1);
    
    uint8_t level = 1;
    uint8_t game_state = 0; //0-Running, 1-EndScreen, 2-Reset
    
    uint8_t map_timer = 0;
    uint8_t movement_timer = 0;
    uint16_t collectable_timer = 0;
    uint16_t number_timer = 0;
    uint16_t timer = 0;
    
    uint8_t numLen = 0;
    int8_t step = 21;
    uint8_t* numArray;
    uint16_t score = 0;

    
    

	//printText("1");
    while (1)
    {
    	pacer_wait();
    	switch(game_state) {
    	
    	case 0: //Running
			if(stats.remainingCollectables == 0) {
				level = (level + 1) % 3;
				map_get(level);
				switch(level) {
					case 1:
					game_state = 1;
						//printText("Play again!  1");
						stats = level_init(map_get(1), collectables.map1);
						break;
					case 2:
						//printText("2");
						stats = level_init(map_get(2), collectables.map2);
						break;
					case 0:
						//printText("3");
						stats = level_init(map_get(3), collectables.map3);
						break;
					default:
						continue;
				}
			}
		
			
			if(map_timer >=2) {
				if(collectable_timer < 50) {
					update_map(stats.collectables, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else if(collectable_timer < 100) {
					update_map(collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				} else {
					collectable_timer = 0;
					update_map(collectables.empty, stats.level, stats.X, stats.Y);
					map_timer = 0;
				}			
			}
			
			map_timer ++;
			movement_timer ++;
			collectable_timer ++;
		
			if(movement_timer >= 10) {
				movement_update(stats.level, &stats);
				collectable_pickup(&stats, stats.collectables);
				header_set(stats.remainingCollectables);
				movement_timer = 0;
			}
			
			timer++;
			if(timer >= PACER_RATE/10) {
				timer = 0;
				score ++;	
			}
			
			ledmat_display_column(0x08, 2);
			break;
		
		case 1: //EndScreen

			numArray = createNumber(score, &numLen);
			
			if(number_timer >= 50) {
				step ++;
				number_timer = 0;
			}
			if(step >= 21) {
				step = 20 - (numLen*4) - 3;
			}
	 
			printNumbers(numArray, step);
			number_timer ++;
			
			navswitch_update ();
			if(navswitch_push_event_p(NAVSWITCH_PUSH)) {
				game_state = 2;
			}
			break;
		
		case 2: //Reset
		
			stats = level_init(map_get(1), collectables.map1);
			level = 1;
			score = 0;
    		timer = 0;
    		step = 21;
    		game_state = 0;
			
			break;			

				
		}
	}
}
