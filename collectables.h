#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include <stdint.h>
#include <stdbool.h>

/* Level Collectable coordinates */
typedef struct {
    uint16_t x1;
    uint16_t y1;
    uint16_t x2;
    uint16_t y2;
    uint16_t x3;
    uint16_t y3;
    uint16_t x4;
    uint16_t y4;
    uint16_t x5;
    uint16_t y5;
} Collect_t;


/* Returns true if location matches a collectable */
bool isCollectable(uint8_t level, uint16_t player_X, uint16_t player_Y);


#endif //COLLECTABLES_H