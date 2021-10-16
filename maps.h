#ifndef MAPS_H
#define MAPS_H

#include <stdint.h>

typedef struct {
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
} maps_t;

typedef struct {
	uint16_t empty[20];
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
	
} map_collectables_t;

/* Level stats */
typedef struct {
    uint16_t level[20]; //Map
    uint16_t collectables[20]; //Collectable Map
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t remainingCollectables; // Boss health

} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init(uint16_t level[], uint16_t collectables[]);
uint16_t* map_get(uint8_t level);
map_collectables_t collectables_init(void);

#endif
