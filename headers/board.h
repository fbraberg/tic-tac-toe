
#ifndef BOARD_H
#define BOARD_H



void init_board();

typedef struct t_Board
{
    char slots[3][3];   
} Board, *PBoard;

#endif