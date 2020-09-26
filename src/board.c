#include "../headers/board.h"


void init_board(PBoard board)
{
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board->slots[row][col] = ' ';
        }
    }
}