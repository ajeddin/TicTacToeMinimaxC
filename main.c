
#include "logic.c"



int main()
    {
    int isAiPlaying;
    playerSelection(&isAiPlaying);
    char continueChoice='y';
    while (continueChoice=='y'){
    
    int choices[9]={0}, counter=0,gameStatus=-2;
    char symbol = 'X';

    char board[3][3]={{'1','2','3'},
                      {'4','5','6'},
                      {'7','8','9'}};


while(gameStatus == -2){

    displayBoard(board);
    printf("\n");
    selectLocation(symbol, board,choices,&counter);
    gameStatus = checkWin(board);
    displayBoard(board);
printf("\n");

if (gameStatus == 10 || gameStatus == -10 || gameStatus == 0  ){
    if(gameStatus==-10){
        printf("Player X Won!!");

    }
    else if(gameStatus==10){
        printf("Player O Won!!");

    }
    else{
        printf("Cats Game");
    }
}
if (!isAiPlaying){
    setTurn(&symbol);
}
else{
    aiMove(board,choices,&counter);
gameStatus = checkWin(board);

    if (gameStatus ==10){
        printf("\n");
    displayBoard(board);
        printf("Computer Wins\n");
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
    printf("\nThanks for playing!\n");
    return 0; 
}