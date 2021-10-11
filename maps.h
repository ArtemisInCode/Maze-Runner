#ifndef MAPS_H
#define MAPS_H

#include <stdint.h>

/* Structure containing maps for each level */
typedef struct {
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
} Maps_t;

/* Structure containing the coordinates of the five collectables*/
typedef struct {
	uint8_t x1;
	uint8_t y1;
	uint8_t x2;
	uint8_t y2;
	uint8_t x3;
	uint8_t y3;
	uint8_t x4;
	uint8_t y4;
	uint8_t x5;
	uint8_t y5;

} Collectables_t;

/* Structure containing the maps of collectables for each level */
typedef struct {
	Collectables_t map1;
	Collectables_t map2;
	Collectables_t map3;
	
} Map_collectables_t;


/* Initialises the maps for all three levels */
Maps_t maps_init(void);
/* Initialises the maps of collectables for all three levels */
Map_collectables_t collectables_init(void);

#endif
