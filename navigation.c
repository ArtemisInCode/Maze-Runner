#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "movement.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10


void display_character (char character)
{
    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


int main (void)
{
    char character = 'A';

    system_init ();

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);

    /* Initialise navigation switch driver.  */
    navswitch_init ();

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait ();
        tinygl_update ();
        
        /* Call the navswitch update function.  */
        navswitch_update ();
        
        if (navswitch_push_event_p (NAVSWITCH_NORTH))
            // TODO: change map NORTH
        if (navswitch_push_event_p (NAVSWITCH_EAST))
            // TODO: change map EAST
        if (navswitch_push_event_p (NAVSWITCH_SOUTH))
            // TODO: change map SOUTH
        if (navswitch_push_event_p (NAVSWITCH_WEST))
            // TODO: change map WEST
        
        display_character (character);
    }
    return 0;
}
