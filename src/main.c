#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "board.h"

typedef struct t_Board
{
    
    char slots[3][3];
    
} Board, *PBoard;
Board board;

void init_board() 
{
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board.slots[row][col] = ' ';
        }
    }
}


void clear_screen()
{
    for(int i = 0; i < 100; i ++) 
    {
	printf("\n");
    }
}

void draw_board()
{
    clear_screen();
    printf("  A   B   C\n");
    printf("1 %c   %c   %c\n", board.slots[0][0], board.slots[0][1], board.slots[0][2]);
    printf("\n");
    printf("2 %c   %c   %c\n", board.slots[1][0], board.slots[1][1], board.slots[1][2]);
    printf("\n");
    printf("3 %c   %c   %c\n", board.slots[2][0], board.slots[2][1], board.slots[2][2]);
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

int empty_1(char move[])
{
    int row = (int) move[0] - '0';
    int col = (int) move[1] - '0';
    printf("This: %c",(board.slots[row][col]));
    return (board.slots[row][col] == ' ');
}

int empty_2(const int row, const int col)
{
    return (board.slots[row][col] == ' ');
}

void place_slot_1(const char* move, char symbol)
{
    int row = (int) move[0] - '0';
    int col = (int) move[1] - '0';
    board.slots[row][col] = symbol;
}

void place_slot_2(const int row, const int col, char symbol)
{
    board.slots[row][col] = symbol;
}

void player_turn()
{
    char res[2];
    char* move;

    printf("Pick a slot: ");
    scanf("%s", res);
    move = decode(res);

    while(!empty_1(move)) 
    {
	printf("Occupied! Pick another slot:\n");
	scanf("%s", res);
	move = decode(res);
    }

    place_slot_1(move, 'O');
}

void player_wins()
{
    clear_screen();
    printf("You win!");
    exit(0);
}

void AI_wins() 
{
    clear_screen();
    printf("The AI wins");
    exit(0);
}

void calc_winner() 
{
    // Check every row
    for(int row = 0; row < 3; row++)
    {
        if(board.slots[row][0] == board.slots[row][1] &&
            board.slots[row][1] == board.slots[row][2]) 
        {
            if(board.slots[row][2] == 'O')
                player_wins();
            else if(board.slots[row][2] == 'X')
                AI_wins();
        }
    }
    
    // Check every column
    for(int col = 0; col < 3; col++)
    {
        if(board.slots[0][col] == board.slots[1][col] &&
            board.slots[1][col] == board.slots[2][col])
        { 
            if(board.slots[2][col] == 'O')
                player_wins();
            else if(board.slots[2][col] == 'X') 
                AI_wins();    
        }
    }
    
    // Check the first diagonal
    if(board.slots[0][0] == board.slots[1][1] &&
       board.slots[1][1] == board.slots[2][2])
    {
        if(board.slots[2][2] == 'O')
            player_wins();
        else if(board.slots[2][2] == 'X') 
            AI_wins();
    }
    
    // Check the second diagonal
    if(board.slots[0][2] == board.slots[1][1] &&
       board.slots[1][1] == board.slots[2][0])
    {
        if(board.slots[2][0] == 'O')
            player_wins();
        else if(board.slots[2][0] == 'X') 
            AI_wins();
    }
}



void AI_turn() 
{
    srand(time(0));
    int row = rand()%3;
    int col = rand()%3;

    while(!empty_2(row, col)) 
    {
	row = rand()%3;
	col = rand()%3;
    }
    place_slot_2(row, col, 'X');
}



void loop()
{
    while(1) 
    {
        draw_board();
        player_turn();
        draw_board();
        calc_winner();
        AI_turn();
        draw_board();
        calc_winner();
    }
}



int main()
{
    init_board();
    loop();
    return 0;
}


