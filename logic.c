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
int checkWin(char board[3][3]);
void playerSelection(int *isAiPlaying);



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

int checkWin(char board[3][3]){
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
//       printf("| %c |", board[i][j]);
      
//     }
//     printf("\n");
//   }}
// // 
//  if ((i + j) % 2 == 0) {
//                 // Even position
//                 printf("\x1b[47m\x1b[30m| %c |", board[i][j]);
//             } else {
//                 // Odd position
//                 printf("\x1b[40m\x1b[37m| %c |", board[i][j]);
//             }
//         }
//         printf("\n");
//     }
// }
if (board[i][j] == 'X') {
                
                printf("\x1b[47m\x1b[97m| %c |\x1b[0m", board[i][j]);
            } else if (board[i][j] == 'O') {
                printf("\x1b[40m\x1b[97m| %c |\x1b[0m", board[i][j]);
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