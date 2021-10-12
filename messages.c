#include "messages.h"


void printText(char *message)
{
    system_init();

    tinygl_init (PACER_RATE); 
    tinygl_font_set (&font5x7_1); 
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    tinygl_text(message);

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        tinygl_update();
    }
    return 0;
}



void gameEnd(Score_t *score, Stats_t lvlStats)
{
    scoreUpdate(score, lvlStats);

    // char endStr =  + score->score;

    printText(endStr);
}
