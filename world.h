/** @file	maps.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Contains all structures to be initialised for gameplay
*/

#ifndef WORLD_H
#define WORLD_H

#include <stdint.h>


/* Structure containing collectable level maps */
typedef struct {
	uint16_t empty[20]; // An empty collectable map
	uint16_t map1[20]; // Collectable map for level 1
	uint16_t map2[20]; // Collectable map for level 2
	uint16_t map3[20]; // Collectable map for level 3
} Map_collectables_t;

/* Level statistics */
typedef struct {
    uint16_t level[20]; // Level map
    uint16_t collectables[20]; // Collectable Map
    uint16_t X; // Player X ordinate
    uint16_t Y; // Player Y ordinate
    uint8_t remainingCollectables; // Collectables yet to be obtained
} Stats_t;


/* Initialisation of level statistics */
Stats_t level_init (uint16_t level[], uint16_t collectables[]);

/* Initialises and returns the map for the specified level */
uint16_t* map_get (uint8_t level);

/* Initialises and returns collectable maps for all levels */
Map_collectables_t collectables_init (void);

#endif // WORLD_H
