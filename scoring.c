#include "scoring.h"
#include "levels.h"

// Base scores off collectables and how many levels?

Score_t score_init(void)
{
    Score_t score;
    score.level = 0;
    score.collectables = 0;
    score.hp = 2;
    score.score = 0;    
    return score;
}

void scoreUpdate(Score_t *score, Stats_t lvlStat)
{
    if (lvlStat.isComplete) {
        score->level += 1;
    }
    score->collectables += lvlStat.numCollects;
    score->hp += lvlStat.playerHP;
    score->score += lvlStat.level * lvlStat.playerHP + lvlStat.numCollects;
}