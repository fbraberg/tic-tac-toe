#include "../headers/ai.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>


// AI has won
void AI_wins()
{
    clear_screen();
    printf("The AI wins");
    exit(0);
}

// The AI makes its move
void AI_turn(PBoard board)
{
    srand(time(0));
    int row = rand()%3;
    int col = rand()%3;

    while(!empty_2(board, row, col))
    {
	row = rand()%3;
	col = rand()%3;
    }
    place_slot_2(board, row, col, AI_SYMBOL);
}
