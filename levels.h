#ifndef LEVELS_H
#define LEVELS_H
#include <stdbool.h>
#include "maps.h"

/* Level stats */
typedef struct {
    uint8_t level; // Level number
    bool isComplete; // Whether this level has been completed
    Maps_t map; // Level map
    Map_collectables_t collectables; // Collectable coordinates
    uint8_t numCollects; // Number of collectables obtained
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t playerHP; // Player health
    uint8_t bossHP; // Boss health

} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init(uint8_t level);

/* Playing of each level */
void play_level(uint16_t map, Stats_t *levelStats);


#endif //LEVELS_H