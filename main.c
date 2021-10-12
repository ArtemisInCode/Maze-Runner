#include <avr/io.h>
#include "ledmat.h"
#include "system.h"
#include "pacer.h"
#include "maps.h"
#include "navswitch.h"
#include "levels.h"

#define PACER_RATE 500

int main (void)
{
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
