#include "board.h"

#ifndef GENERAL_H
#define GENERAL_H

// General settings and macros
#define DEBUG 0
#define CONSOLE_CLEAR 100
#define PLAYER_SYMBOL 'O'
#define AI_SYMBOL 'X'

// Clears the screen
void clear_screen(void);
void draw_board(PBoard board);

#endif
