/** @file	messages.h
    @author A. Hingston, R. Beck
    @date   19 Oct 2021
    @brief  Support to print text to LED matrix
*/

#ifndef MESSAGES_H
#define MESSAGES_H

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdio.h>

#define PACER_RATE 500
#define MESSAGE_RATE 10

/* Prints a message to LED screen */
void printText(char *message);

/* Message displays at end of game */
void gameEnd(timer_tick_t time);

#endif // MESSAGES_H