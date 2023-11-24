#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
bool checkLine(char a, char b, char c);
void displayBoard(char board[3][3]);
void selectLocation(char symbol,char board[3][3],int choices[],int *counter);
void setTurn(char *symbol);
void aiMove(char board[3][3], int choices[],int *counter);
int minimax(char board[3][3],int depth, int isMaxingorMining);
int checkWin(char board[3][3]);
void playerSelection(int *isAiPlaying);


bool checkLine(char a, char b, char c) {
    return (a != '1' && a == b && a == c);
}

void playerSelection(int *isAiPlaying){
printf("Play Selection:\n0.PvP\n1.Against AI\n");
    scanf("%d",isAiPlaying);
    while (*isAiPlaying!=1 && *isAiPlaying !=0)
    {
    
    printf("Invalid Input\n");
    printf("Play Selection:\n0.PvP\n1.Against AI\n");
    scanf("%d",isAiPlaying);
    }
}

int checkWin(char board[3][3]){
    // int gameStatus = 0;
    // if ((((board[0][0]==board[0][1]&&board[0][0]==board[0][2])&&board[0][0]=='X')||((board[0][0]==board[1][0]&&board[0][0]==board[2][0])&&board[0][0]=='X')||((board[0][2]==board[1][2]&&board[0][2]==board[2][2])&&board[0][2]=='X')||((board[2][2]==board[2][1]&&board[2][2]==board[2][0])&&board[2][2]=='X')||((board[0][0]==board[1][1]&&board[0][0]==board[2][2])&&board[0][0]=='X')||((board[2][0]==board[1][1]&&board[2][0]==board[0][2])&&board[2][0]=='X')||((board[0][1]==board[1][1]&&board[0][1]==board[2][1])&&board[0][1]=='X')||((board[1][0]==board[1][1]&&board[1][0]==board[1][2])&&board[1][0]=='X'))){
    //     return -10;

    // }
    // else if ((((board[0][0]==board[0][1]&&board[0][0]==board[0][2])&&board[0][0]=='O')||((board[0][0]==board[1][0]&&board[0][0]==board[2][0])&&board[0][0]=='O')||((board[0][2]==board[1][2]&&board[0][2]==board[2][2])&&board[0][2]=='O')||((board[2][2]==board[2][1]&&board[2][2]==board[2][0])&&board[2][2]=='O')||((board[0][0]==board[1][1]&&board[0][0]==board[2][2])&&board[0][0]=='O')||((board[2][0]==board[1][1]&&board[2][0]==board[0][2])&&board[2][0]=='O')||((board[0][1]==board[1][1]&&board[0][1]==board[2][1])&&board[0][1]=='O')||((board[1][0]==board[1][1]&&board[1][0]==board[1][2])&&board[1][0]=='O'))){
    //     return 10;

    // }
    if (board[0][0]!='1' && board[0][1]!='2' &&board[0][2]!='3' &&board[1][0]!='4' &&board[1][1]!='5' &&board[1][2]!='6' &&board[2][0]!='7' &&board[2][1]!='8' &&board[2][2]!='9' )
{ 
                return 0;
}

  for (int i = 0; i < 3; ++i) {
     if (checkLine(board[0][i], board[1][i], board[2][i])) {
            return (board[0][i] == 'X') ? -10 : 10;
        }
    if (checkLine(board[i][0], board[i][1], board[i][2])) {
            return (board[i][0] == 'X') ? -10 : 10;
        }
    if (checkLine(board[0][0], board[1][1], board[2][2])) {
        return (board[0][0] == 'X') ? -10 : 10;
    }
    if (checkLine(board[0][2], board[1][1], board[2][0])) {
        return (board[0][2] == 'X') ? -10 : 10;
    }
    }
 

return -2;
}

void aiMove(char board[3][3],int choices[],int *counter){
     int bestScore = INT_MIN;
    int bestMove[2] ;
        for (int row = 0;row<3;row++){
        for (int col = 0;col<3;col++){
        if (board[row][col]<59){
        char initial = board[row][col];

            board[row][col] = 'O';

        int score = minimax(board,0,0);
            board[row][col] = initial;
        if (score > bestScore){
            bestScore=score;
            bestMove[0] = row;
            bestMove[1] = col; 
        }

        }
    }
    }
    int val =  board[bestMove[0]][bestMove[1]] - '0';
            choices[*counter] =  val;
    *counter += 1;
    board[bestMove[0]][bestMove[1]] = 'O';

}


int minimax(char board[3][3],int depth, int isMaxingorMining){
    int result =   checkWin(board);
    if (result !=-2){
        return result;
    }
    if (isMaxingorMining == 1){
        int bestScore = INT_MIN;
 for (int row = 0;row<3;row++){
for (int col = 0;col<3;col++){
if (board[row][col]<59){

        char initial = board[row][col];
        board[row][col] = 'O';
        int score = minimax(board,depth+1,0);
        board[row][col] = initial;
        if (score > bestScore){
            bestScore=score;
        }

        }
        }} 
        return bestScore;
    }
    else
    {
 int bestScore = INT_MAX;
 for (int row = 0;row<3;row++){
        for (int col = 0;col<3;col++){
        if (board[row][col]<59){
        char initial = board[row][col];

        board[row][col] = 'X'; //Human input
        int score = minimax(board,depth+1,1); // is maxing and depth +1. 
        board[row][col] = initial; // resetting the change done on 212 

        if (score < bestScore){ 
            bestScore=score;
        }

        }}} 
        return bestScore;
    }
}
void setTurn(char *symbol){
    if (*symbol == 'X'){
        *symbol = 'O';
    }
    else{
        *symbol = 'X';

    }
}

void displayBoard(char board[3][3]){
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
if (board[i][j] == 'X') {
                
                printf("\x1b[47m\x1b[97m| %c |\x1b[0m", board[i][j]);
            } else if (board[i][j] == 'O') {
                printf("\x1b[41m\x1b[97m| %c |\x1b[0m", board[i][j]);
            } else {
                printf("| %c |", board[i][j]);
            }
        }
        printf("\n");
    }
}

void selectLocation(char symbol,char board[3][3],int choices[],int *counter){
    int playerChoice, isTaken;
    
    printf("Please input where you want to put in your %c\t",symbol);
    scanf("%d",&playerChoice);
    while (playerChoice>9 || playerChoice<0){
        printf("Location choice should be in the range of 1-9");
        scanf("%d",&playerChoice);


    }

    do {
        for (int x =0;x<9;x++){
            if (choices[x] == playerChoice){
                isTaken = 1;
                break;
            }  
            else{
                isTaken= 0;
            }

        }
        if (isTaken==1)
        {
printf("\nLocation already taken:\t");
        scanf("%d",&playerChoice);
        continue;  
              }
        
    }while(isTaken == 1);
    choices[*counter] = playerChoice;
    *counter += 1;
    board[(playerChoice - 1)/3][(playerChoice-1)%3]= symbol;
}
