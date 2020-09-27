#include "../headers/board.h"

static void t_update_board(PBoard board) {
    // This is where the magic happens
}

void init_board(PBoard board)
{
    board->player_can_finish = 0;
    board->ai_can_finish = 0;
    board->ai_can_finish_next_turn = 0;
    board->update_board = t_update_board;

    for(int row = 0; row < BOARD_HEIGHT; row++) {
        for(int col = 0; col < BOARD_WIDTH; col++) {
            board->slots[row][col] = ' ';
        }
    }
}

// Checks if move is possible based on move
// Returns: 1 if move possible, 0 if not possible
int empty_1(PBoard board, char move[])
{
    int row = (int) move[0] - '0';
    int col = (int) move[1] - '0';
    return (board->slots[row][col] == ' ');
}

// Checks if move is possible based on two coordinates
// Returns: 1 if move possible, 0 if not possible
int empty_2(PBoard board, const int row, const int col)
{
    return (board->slots[row][col] == ' ');
}

// Places symbol in slot based on a move
void place_slot_1(PBoard board, const char* move, char symbol)
{
    int row = (int) move[0] - '0';
    int col = (int) move[1] - '0';
    board->slots[row][col] = symbol;
}

// Places symbol in slot based on two coordinates
void place_slot_2(PBoard board,const int row, const int col, char symbol)
{
    board->slots[row][col] = symbol;
}
