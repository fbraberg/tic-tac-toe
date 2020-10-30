#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "../headers/board.h"
#include "../headers/general.h"
#include "../headers/ai.h"


char* decode(char* move)
{
    int row;
    int col;
    static char res[2];

    if (move[1] == '1')
	row = 0;
    else if (move[1] == '2')
	row = 1;
    else
	row = 2;

    if (move[0] == 'A')
	col = 0;
    else if (move[0] == 'B')
	col = 1;
    else
	col = 2;

    res[0] = row + '0';
    res[1] = col + '0';
    return res;

}


// Player makes a choice and tries to make the move
void player_turn(PBoard board)
{
    char res[2];
    char* move;

    printf("Pick a slot: ");
    scanf("%s", res);
    move = decode(res);

    while(!empty_1(board, move))
    {
	printf("Occupied! Pick another slot:\n");
	scanf("%s", res);
	move = decode(res);
    }

    place_slot_1(board, move, PLAYER_SYMBOL);
}

// Player has won
void player_wins()
{
    clear_screen();
    printf("You win!");
    exit(0);
}



// Search entire board and check if there's a winner
void calc_winner(PBoard board)
{
    // Check every row
    for(int row = 0; row < 3; row++)
    {
        if(board->slots[row][0] == board->slots[row][1] &&
            board->slots[row][1] == board->slots[row][2])
        {
            if(board->slots[row][2] == PLAYER_SYMBOL)
                player_wins();
            else if(board->slots[row][2] == AI_SYMBOL)
                AI_wins();
        }
    }

    // Check every column
    for(int col = 0; col < 3; col++)
    {
        if(board->slots[0][col] == board->slots[1][col] &&
            board->slots[1][col] == board->slots[2][col])
        {
            if(board->slots[2][col] == PLAYER_SYMBOL)
                player_wins();
            else if(board->slots[2][col] == AI_SYMBOL)
                AI_wins();
        }
    }

    // Check the first diagonal
    if(board->slots[0][0] == board->slots[1][1] &&
       board->slots[1][1] == board->slots[2][2])
    {
        if(board->slots[2][2] == PLAYER_SYMBOL)
            player_wins();
        else if(board->slots[2][2] == AI_SYMBOL)
            AI_wins();
    }

    // Check the second diagonal
    if(board->slots[0][2] == board->slots[1][1] &&
       board->slots[1][1] == board->slots[2][0])
    {
        if(board->slots[2][0] == PLAYER_SYMBOL)
            player_wins();
        else if(board->slots[2][0] == AI_SYMBOL)
            AI_wins();
    }
}

// Main game loop
void loop(PBoard board)
{
    while(1)
    {
        draw_board(board);
        player_turn(board);
        draw_board(board);
        calc_winner(board);
        AI_turn(board);
        draw_board(board);
        calc_winner(board);
    }
}



int main()
{
    Board board;
    init_board(&board);
    loop(&board);
    return 0;
}
