#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "../headers/board.h"
#include "../headers/general.h"


// Clears the screen
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



// ==================================/AI functions\==================================

// AI has won
void ai_wins()
{
    clear_screen();
    printf("The AI wins");
    exit(0);
}

int ai_can_win_this_turn()
{

}

void ai_finish_game()
{


}

int player_can_win_next_turn()
{


}

void ai_block_player()
{


}

int ai_can_win_in_two_turns()
{

}

void ai_play_accordingly()
{

}

void ai_play_on_mood()
{

}

// The AI makes its move
void AI_turn(PBoard board)
{
    int row;
    int col;

    // =======================To be improved================================

    if( ai_can_win_this_turn() )
        ai_finish_game();
    else if( player_can_win_next_turn() )
        ai_block_player();
    else if( ai_can_win_in_two_turns() )
        ai_play_accordingly();
    else
        ai_play_on_mood();

    // ========================================================================



    while(!empty_2(board, row, col))
    {
	row = rand()%3;
	col = rand()%3;
    }
    place_slot_2(board, row, col, AI_SYMBOL);

}

// ==================================\AI functions/==================================

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
                ai_wins();
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
                ai_wins();
        }
    }

    // Check the first diagonal
    if(board->slots[0][0] == board->slots[1][1] &&
       board->slots[1][1] == board->slots[2][2])
    {
        if(board->slots[2][2] == PLAYER_SYMBOL)
            player_wins();
        else if(board->slots[2][2] == AI_SYMBOL)
            ai_wins();
    }

    // Check the second diagonal
    if(board->slots[0][2] == board->slots[1][1] &&
       board->slots[1][1] == board->slots[2][0])
    {
        if(board->slots[2][0] == PLAYER_SYMBOL)
            player_wins();
        else if(board->slots[2][0] == AI_SYMBOL)
            ai_wins();
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
