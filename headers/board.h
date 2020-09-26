
#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3


void init_board();

typedef struct t_Board
{
    char slots[3][3];   
} Board, *PBoard;

#endif