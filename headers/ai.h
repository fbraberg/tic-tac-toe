#ifndef AI_H
#define AI_H

#include "board.h"

typedef struct t_ai
{
    char* finishing_move;
    char* players_finishing_move;
    char* finishing_chain[];

} AI, *PAI;

void ai_play(PBoard board, PAI ai);
//void try_make_move(PBoard board, PAI ai);
void ai_finish_game(PBoard board, PAI ai);
void ai_block_player(PBoard board, PAI ai);
void ai_play_accordingly(PBoard board, PAI ai);
void ai_play_on_mood(PBoard board, PAI ai);

#endif
