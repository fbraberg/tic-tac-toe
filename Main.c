#include <stdio.h>
#include <string.h>

typedef struct t_Board
{
    /*   char row_A[3] = {' ', ' ', ' '};
    char row_B[3] = {' ', ' ', ' '};
    char row_C[3] = {' ', ' ', ' '};    */
    
    char slots[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

} Board;
Board board;

void drawBoard()
{
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

// FIX
bool empty(char move[])
{
    char row = move[0];
    char col = move[1];
    if(board.slots[row][col] != ' ')
    { 
        printf("THIS BE IN IT:   %c§\n", board.slots[0][0]);
        printf("Occupied! Pick another slot\n");
        return false;
    }
    return true;
}

void placeSlot(const char* move)
{
    
}

void playerTurn()
{
    char res[2];
    char* move;
    
    printf("Pick a slot: ");
    do {
        scanf("%s", res);
        move = decode(res);
    }
    while(!empty(move));
    
    placeSlot(move);
}

void calc_Winner() 
{
    
}


void AI_turn();



void loop()
{
    drawBoard();
    playerTurn();
    drawBoard();
    //calcWinner();
    //AI turn
    //Draw board
    //Clac winner
}



int main()
{
    loop();


    return 0;
}


