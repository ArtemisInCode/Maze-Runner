/** @file	maps.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Contains all structures to be initialised for gameplay
*/

#ifndef MAPS_H
#define MAPS_H

#include <stdint.h>

/* Structure containing level maps */
typedef struct {
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
} Maps_t;

/* Structure containing collectable level maps */
typedef struct {
	uint16_t empty[20];
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
} Map_collectables_t;

/* Level statistics */
typedef struct {
    uint16_t level[20]; //Map
    uint16_t collectables[20]; //Collectable Map
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t remainingCollectables; // Collectables yet to ne obtained

} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init(uint16_t level[], uint16_t collectables[]);

/* Initialises and returns the map for the specified level */
uint16_t* map_get(uint8_t level);

/* Initialises and returns collectable maps for all levels */
Map_collectables_t collectables_init(void);

#endif
