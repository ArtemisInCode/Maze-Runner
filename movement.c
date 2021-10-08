#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include "movement.h"
#include "navswitch.h"




static void display_column (uint8_t row_pattern, uint8_t current_column)
{
    pio_output_high (cols[prev_column]);

    for (uint8_t i = 0; i < LEDMAT_ROWS_NUM; i++) {
        if ((row_pattern >> i) & 1) {
            pio_output_low (rows[i]);
        } else {
            pio_output_high (rows[i]);
        }
    }

    pio_output_low (cols[current_column]);
    prev_column = current_column;   
}

void display_map (uint8_t bitmap)
{
    uint8_t current_column = 0;
  
    system_init ();
    pacer_init (500);
    
    /* Initialise LED matrix pins. */
    for (uint8_t i = 0; i < LEDMAT_ROWS_NUM; i++) {
        pio_config_set (rows[i], PIO_OUTPUT_HIGH);
    }

    for (uint8_t j = 0; j < LEDMAT_COLS_NUM; j++) {
        pio_config_set (cols[j], PIO_OUTPUT_HIGH);
    }

    while (1)
    {
        pacer_wait ();
        
        display_column (bitmap[current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }           
    }
}

void navigation (uint16_t map, uint16_t player_X, uint16_t player_Y)
{
    //TODO: use map select initial bitmap using player_X and player_Y coords

    system_init ();
    navswitch_init ();
    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait ();
        navswitch_update ();
        
        if (navswitch_push_event_p (NAVSWITCH_NORTH))
            // TODO: change map NORTH
        if (navswitch_push_event_p (NAVSWITCH_EAST))
            // TODO: change map EAST
        if (navswitch_push_event_p (NAVSWITCH_SOUTH))
            // TODO: change map SOUTH
        if (navswitch_push_event_p (NAVSWITCH_WEST))
            // TODO: change map WEST
        
        display_map (map);
    }
    return 0;
}