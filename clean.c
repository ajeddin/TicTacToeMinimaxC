//Abdulaziz Jamaleddin 
//Kim M
//TicTacToe

// void boardCopyFunc(char boardCopy[3][3], char board[3][3]);
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>



void displayBoard(char board[3][3]);
void selectLocation(char symbol,char board[3][3],int choices[],int *counter);
void setTurn(char *symbol);
void aiMove(char board[3][3], int choices[],int *counter);
void checkForWin(char board[3][3],int *gameStatus);
int minimax(char board[3][3],int depth, int isMaxingorMining);
int checkForWinCopy(char board[3][3]);
int main()
    {
        int isAiPlaying=1;
    printf("Play Selection:\n0.PvP\n1.Against AI\n");
    scanf("%d",&isAiPlaying);
    while (isAiPlaying!=1 && isAiPlaying !=0)
    {
    
    printf("Play Selection:\n0.PvP\n1.Against AI\n");
    scanf("%d",&isAiPlaying);
    }
    
    
    char continueChoice='y';
    while (continueChoice=='y'){
    
    int choices[9]={0}, counter=0,gameStatus=0;
    char symbol = 'X';

    char board[3][3]={{'1','2','3'},
                      {'4','5','6'},
                      {'7','8','9'}};


while(gameStatus == 0){

    displayBoard(board);
    printf("\n");
    selectLocation(symbol, board,choices,&counter);
checkForWin(board,&gameStatus);
    displayBoard(board);
printf("\n");

if (gameStatus == 1 || gameStatus == -1 ){
    // if(gameStatus == 1 && board[0][0]=='O'&& board[2][2]=='O'&& board[1][1]=='O')
    // {displayBoard(board);
    // printf("Player O Won!!");
    // }
    // else if(gameStatus == 1 && board[0][0]=='X'&& board[2][2]=='X'&& board[1][1]=='X')
    // {displayBoard(board);
    // printf("Player X Won!!");
    // }
    if(gameStatus==1){
        printf("Player %c Won!!",symbol);

    }
    else{
        printf("No Win");
    }
    break;
}
if (!isAiPlaying){
    setTurn(&symbol);
}
else{
    aiMove(board,choices,&counter);
    checkForWin(board,&gameStatus);
    if (gameStatus ==1){
        printf("\n");
    displayBoard(board);
        printf("AI WON!!\n");
    }
}
}



printf("\nWould you like to play again? Y/N");
scanf("\n%c",&continueChoice);
continueChoice = tolower(continueChoice);
while (continueChoice!='y'&&continueChoice!='n')
{
printf("\nWould you like to play again? Y/N");
scanf("\n%c",&continueChoice);
}

    }
    return 0; 
}


void checkForWin(char board[3][3],int *gameStatus){
    // int gameStatus = 0;
    if ((board[0][0]==board[0][1]&&board[0][0]==board[0][2])||(board[0][0]==board[1][0]&&board[0][0]==board[2][0])){
        // if (board[0][0]=='O'){
        //     printf("AI WON");
        // }
        *gameStatus = 1;

    }
    else if ((board[0][2]==board[1][2]&&board[0][2]==board[2][2])||(board[2][2]==board[2][1]&&board[2][2]==board[2][0])){
        // if (board[0][2]=='O'){
        //     printf("AI WON");
        // }
        *gameStatus = 1;
    }
    else if((board[0][0]==board[1][1]&&board[0][0]==board[2][2])||(board[2][0]==board[1][1]&&board[2][0]==board[0][2])){
        //  if (board[0][0]=='O'){
        //     printf("AI WON");
        // }
        *gameStatus = 1;

    }
    else if((board[1][0]==board[1][1]&&board[1][0]==board[1][2])||(board[0][1]==board[1][1]&&board[0][1]==board[2][1])){
        //  if (board[0][0]=='O'){
        //     printf("AI WON");
        // }
        *gameStatus = 1;

    }
    else if (board[0][0]!='1' && board[0][1]!='2' &&board[0][2]!='3' &&board[1][0]!='4' &&board[1][1]!='5' &&board[1][2]!='6' &&board[2][0]!='7' &&board[2][1]!='8' &&board[2][2]!='9' )
{ //USE CHOICES ARRAY INSTEAD SOMETIME 
    *gameStatus = -1;
}}

int checkForWinCopy(char board[3][3]){
    // int gameStatus = 0;
    if ((((board[0][0]==board[0][1]&&board[0][0]==board[0][2])&&board[0][0]=='X')||((board[0][0]==board[1][0]&&board[0][0]==board[2][0])&&board[0][0]=='X')||((board[0][2]==board[1][2]&&board[0][2]==board[2][2])&&board[0][2]=='X')||((board[2][2]==board[2][1]&&board[2][2]==board[2][0])&&board[2][2]=='X')||((board[0][0]==board[1][1]&&board[0][0]==board[2][2])&&board[0][0]=='X')||((board[2][0]==board[1][1]&&board[2][0]==board[0][2])&&board[2][0]=='X')||((board[0][1]==board[1][1]&&board[0][1]==board[2][1])&&board[0][1]=='X')||((board[1][0]==board[1][1]&&board[1][0]==board[1][2])&&board[1][0]=='X'))){
        return -10;

    }
    else if ((((board[0][0]==board[0][1]&&board[0][0]==board[0][2])&&board[0][0]=='O')||((board[0][0]==board[1][0]&&board[0][0]==board[2][0])&&board[0][0]=='O')||((board[0][2]==board[1][2]&&board[0][2]==board[2][2])&&board[0][2]=='O')||((board[2][2]==board[2][1]&&board[2][2]==board[2][0])&&board[2][2]=='O')||((board[0][0]==board[1][1]&&board[0][0]==board[2][2])&&board[0][0]=='O')||((board[2][0]==board[1][1]&&board[2][0]==board[0][2])&&board[2][0]=='O')||((board[0][1]==board[1][1]&&board[0][1]==board[2][1])&&board[0][1]=='O')||((board[1][0]==board[1][1]&&board[1][0]==board[1][2])&&board[1][0]=='O'))){
        return 10;

    }
    else if (board[0][0]!='1' && board[0][1]!='2' &&board[0][2]!='3' &&board[1][0]!='4' &&board[1][1]!='5' &&board[1][2]!='6' &&board[2][0]!='7' &&board[2][1]!='8' &&board[2][2]!='9' )
{ //USE CHOICES ARRAY INSTEAD SOMETIME 
                return 0;
}
return -2;
}

void aiMove(char board[3][3],int choices[],int *counter){
// int bestScore = -INFINITY;
     int bestScore = INT_MIN;

    int bestMove[2] ;
    // char boardCopy[3][3];

    // printf("\n2121");
    // boardCopyFunc(boardCopy,board);
    
        for (int row = 0;row<3;row++){
        for (int col = 0;col<3;col++){
        if (board[row][col]<59){
        char initial = board[row][col];

            // printf("\n%c",boardCopy[row][col]);
            board[row][col] = 'O';

        int score = minimax(board,0,0); //1 is maxing
            board[row][col] = initial;
        // boardCopyFunc(boardCopy,board);
        if (score > bestScore){
            bestScore=score;
            bestMove[0] = row;
            bestMove[1] = col; 
        }

        }
    }
    }
    // printf("\n\n%d\n\n%d",bestMove[0],bestMove[1]);
    // int atoi(char board[bestMove[0]][bestMove[1]]);

    int val =  board[bestMove[0]][bestMove[1]] - '0';
            choices[*counter] =  val;
    *counter += 1;
    board[bestMove[0]][bestMove[1]] = 'O';

}


int minimax(char board[3][3],int depth, int isMaxingorMining){
    // checkForWin
    int result =   checkForWinCopy(board);
    // displayBoard(board);
    // printf("\n");
    // printf("\n%d",result);
    if (result !=-2){
        return result;
    }

        // char boardCopy[3][3];
        // boardCopyFunc(boardCopy,board);
    if (isMaxingorMining == 1){
        int bestScore = INT_MIN;
 for (int row = 0;row<3;row++){
for (int col = 0;col<3;col++){
if (board[row][col]<59){

        char initial = board[row][col];
        board[row][col] = 'O';
        int score = minimax(board,depth+1,0);
        // printf("\n\n%d",score);
        board[row][col] = initial;
        // boardCopyFunc(boardCopy,board);
        if (score > bestScore){
            bestScore=score;
        }

        }
        }} 
        return bestScore;
    }
    // else if (isMaxingorMining == 0)
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

        // boardCopyFunc(boardCopy,board);
        if (score < bestScore){ 
            bestScore=score;
        }

        }}} 
        return bestScore;
    }
}


// void boardCopyFunc(char boardCopy[3][3], char board[3][3]){

//     for (int row = 0;row<3;row++){
//     for (int col = 0;col<3;col++){
//         boardCopy[row][col] = board[row][col];}}
    
// }
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
      printf("| %c |", board[i][j]);
      
    }
//     0 1 2    
//  0  1 2 3 
//  1  4 5 6
//  2  7 8 9

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
printf("\nLocation already taken\n");
        scanf("%d",&playerChoice);
        continue;  
              }
        
    }while(isTaken == 1);
    choices[*counter] = playerChoice;
    *counter += 1;
    
    switch (playerChoice) {

    case 1:
  
    board[0][0] = symbol;
    break;
    case 2:

    board[0][1] = symbol;
    break;
    case 3:
  
    board[0][2] = symbol;
    break;
    case 4:

    board[1][0] = symbol;
    break;
    case 5:

    board[1][1] = symbol;
    break;
    case 6:

    board[1][2] = symbol;
    break;
    case 7:

    board[2][0] = symbol;
    break;
    case 8:

    board[2][1] = symbol;
    break;
    case 9:
    board[2][2] = symbol;
    break;
    }
}