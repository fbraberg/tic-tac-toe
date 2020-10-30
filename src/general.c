#include "../headers/general.h"
#include "../headers/board.h"
#include "stdio.h"

void clear_screen()
{
    for(int i = 0; i < CONSOLE_CLEAR ; i++)
        printf("\n");
}

// Draws the board on screen
void draw_board(PBoard board)
{
    clear_screen();
    printf("  A   B   C\n");
    printf("1 %c   %c   %c\n", board->slots[0][0], board->slots[0][1], board->slots[0][2]);
    printf("\n");
    printf("2 %c   %c   %c\n", board->slots[1][0], board->slots[1][1], board->slots[1][2]);
    printf("\n");
    printf("3 %c   %c   %c\n", board->slots[2][0], board->slots[2][1], board->slots[2][2]);
}
