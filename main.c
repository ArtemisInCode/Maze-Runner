// Several of these are almost certainly redundant

#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"
#include "timer.h"
#include "messages.h"

#define PACER_RATE 500

int main (void)
{
	timer_tick_t time;
    system_init ();
	timer_init ();
    ledmat_init();
    pacer_init(PACER_RATE);;
    map_collectables_t collectables = collectables_init();
    Stats_t stats = level_init(map_get(1), collectables.map1);
    
    
    uint8_t level = 1;
    uint8_t map_timer = 0;
    uint8_t movement_timer = 0;
    uint16_t collectable_timer = 0;
    
    

	printText("1");
    while (1)
    {
    
		if(stats.remainingCollectables == 0) {
			level ++;
			map_get(level);
			switch(level) {
				case 2:
					printText("2");
					stats = level_init(map_get(2), collectables.map2);
					break;
				case 3:
					printText("3");
					stats = level_init(map_get(3), collectables.map3);
					break;
				default:
					continue;
			}
		}
    
    	pacer_wait();
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
			movement_timer = 0;
		}
		
		ledmat_display_column(0x08, 2);
		
		
	

			
		}
		time = timer_get ();

		gameEnd(&time);
}
