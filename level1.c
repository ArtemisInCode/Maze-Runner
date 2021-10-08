#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include "movement.h"
#include "navswitch.h"
//TODO: #include "maps.h"


void play_level_1(maps_t maps) {
    // TODO: Initialise player coordinates
    uint16_t player_X;
    uint16_t player_Y;
    // TODO: select uint16_t map from maps

    while (1)
    {
        navigation (map, player_X, player_Y);
    }
    
}