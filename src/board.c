#include "../headers/board.h"


void init_board(PBoard board)
{
    for(int row = 0; row < BOARD_HEIGHT; row++) {
        for(int col = 0; col < BOARD_WIDTH; col++) {
            board->slots[row][col] = ' ';
        }
    }
}