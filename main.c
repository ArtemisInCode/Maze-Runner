#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"

#define PACER_RATE 600

int main (void)
{
    system_init ();
    ledmat_init();
    pacer_init(PACER_RATE);
    maps_t maps = maps_init();
    map_collectables_t collectables = collectables_init();
    Stats_t stats = level_init(maps.map1, collectables.map1);
    
    uint8_t map_timer = 0;
    uint8_t movement_timer = 0;
    uint16_t collectable_timer = 0;
    
    


    while (1)
    {
    	pacer_wait();
		if(map_timer >=2) {
			if(collectable_timer < 50) {
				update_map(collectables.map1, maps.map1, stats.X, stats.Y);
				map_timer = 0;
			} else if(collectable_timer < 100) {
				update_map(collectables.empty, maps.map1, stats.X, stats.Y);
				map_timer = 0;
			} else {
				collectable_timer = 0;
				update_map(collectables.empty, maps.map1, stats.X, stats.Y);
				map_timer = 0;
			}			
		}
		
		map_timer ++;
		movement_timer ++;
		collectable_timer ++;
	
		if(movement_timer >= 10) {
			movement_update(maps.map1, &stats);
			collectable_pickup(&stats, collectables.map1);
			movement_timer = 0;
		}
		
		ledmat_display_column(0x08, 2);
		
		
	

			
		}
}
