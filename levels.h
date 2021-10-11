#ifndef LEVELS_H
#define LEVELS_H
#include "maps.h"

/* Level stats */
typedef struct {
    uint8_t level; // Level number
    Maps_t map; // Level map
    Map_collectables_t collectables; // Collectable coordinates
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t playerHP; // Player health
    uint8_t bossHP; // Boss health

} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init(uint8_t level);

/* Playing of each level */
void play_level(Maps_t maps);


#endif //LEVELS_H