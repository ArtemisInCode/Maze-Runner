#ifndef MAPS_H
#define MAPS_H

#include <stdint.h>

typedef struct {
	uint16_t map1[20];
	uint16_t map2[20];
	uint16_t map3[20];
} maps_t;

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

} collectables_t;

typedef struct {
	collectables_t map1;
	collectables_t map2;
	collectables_t map3;
	
} map_collectables_t;



maps_t maps_init(void);
map_collectables_t collectables_init(void);

#endif
