
#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

typedef struct t_board Board, *PBoard;
struct t_board
{
    char slots[3][3];
    int player_can_finish;
    int ai_can_finish;
    int ai_can_finish_next_turn;
    void (*update_board)(Board*);
};

void init_board();
int empty_1(PBoard board, char move[]);
int empty_2(PBoard board, const int row, const int col);
void place_slot_1(PBoard board, const char* move, char symbol);
void place_slot_2(PBoard board,const int row, const int col, char symbol);

#endif
