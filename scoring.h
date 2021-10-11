#ifndef SCORING_H
#define SCORING_H

#include <stdint.h>


/* Game score */
typedef struct {
    uint8_t level; // Highest level completed
    uint8_t collectables; // Number of collectables obtained
    uint8_t hp; // Overall health (lost/gained)
    uint8_t score;
} Score_t;

/* Initialises the game score */
Score_t score_init(void);

/* Updates the game score */
void scoreUpdate(Score_t *score, Stats_t lvlStat);

#endif //SCORING_H