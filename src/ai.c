#include "../headers/ai.h"
#include "../headers/general.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



void ai_finish_game(PBoard board, PAI ai)
{
    place_slot_1(board, ai->finishing_move, AI_SYMBOL);
}

void ai_block_player(PBoard board, PAI ai)
{
    place_slot_1(board, ai->players_finishing_move, AI_SYMBOL);
}

void ai_play_accordingly(PBoard board, PAI ai)
{
    int length = sizeof(*(ai->finishing_chain)) / sizeof(ai->finishing_chain[0]);
    for (int move = 0; move < length; move++) {
        place_slot_1(board, ai->finishing_chain[move], AI_SYMBOL);
    }
}

void ai_play_on_mood(PBoard board, PAI ai)
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

// The AI makes its move
void ai_play(PBoard board, PAI ai)
{
    if( board->ai_can_finish )
        ai_finish_game(board, ai);
    else if( board->player_can_finish )
        ai_block_player(board, ai);
    else if( board->ai_can_finish_next_turn )
        ai_play_accordingly(board, ai);
    else
        ai_play_on_mood(board, ai);
}
