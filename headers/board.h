
#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3


typedef struct t_Board
{
    char slots[3][3];   
} Board, *PBoard;

void init_board();
int empty_1(PBoard board, char move[]);
int empty_2(PBoard board, const int row, const int col);
void place_slot_1(PBoard board, const char* move, char symbol);
void place_slot_2(PBoard board,const int row, const int col, char symbol);

#endif