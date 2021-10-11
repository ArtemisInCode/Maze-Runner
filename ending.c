#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include"levels.h"
#include"scoring.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10

void printEnd(Score_t *score, Stats_t lvlStats)
{
    system_init();

    tinygl_init (PACER_RATE); 
    tinygl_font_set (&font5x7_1); 
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    scoreUpdate(score, lvlStats);

    tinygl_text("Game over! Final score: %d", score->score);

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        
        tinygl_update();
        
    }
    return 0;
}
