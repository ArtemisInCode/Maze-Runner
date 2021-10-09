#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "system.h"
#include "pio.h"
#include "pacer.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define PACER_RATE 500

static uint8_t prev_column = 0;

/* Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

/* Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

/* Selects the column to be displayed */
static void display_column (uint8_t row_pattern, uint8_t current_column);

/* Displays the maps to the lED screen */
void display_map (uint8_t bitmap);

/* Checks whether player move is legal */
bool isLegalMove (uint16_t map, uint16_t player_X, uint16_t player_Y);

/* Allows the player to navigate around the map */
void navigation (uint16_t map, uint16_t player_X, uint16_t player_Y);

#endif //MOVEMENT_H