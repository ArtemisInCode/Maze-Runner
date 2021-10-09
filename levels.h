#ifndef LEVELS_H
#define LEVELS_H

//TODO: #include "maps.h"

/* Level stats */
typedef struct {
    maps_t map; // Level map
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t playerHP; // Player health
    uint8_t bossHP; // Boss health

} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init(uint8_t level);

/* Playing of each level */
void play_level(maps_t maps);


#endif //LEVELS_H