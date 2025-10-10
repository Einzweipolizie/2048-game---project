#include "stdio.h"
#include "stdlib.h"

#include "header.h"


int cantMove(){ // 1) cheking if all == 0    2) cheking if there nerr any number that  is same number    3) the same but veticaly
    
    for(int i = 0; i < 4; i++){ // cheeks if 0
        for(int k = 0; k < 4; k++){
            if(board[i][k] == 0){
                return 1;
            }

        }
    }

    for(int i = 0; i < 4; i++){ //chekes in x 
        for(int k = 0; k < 3; k++){
            if(board[i][k] ==  board[i][k+1]){
                return 1;
            }

        }
    }
    for(int k = 0; k < 4; k++){ //Cheks verticaly
        for(int i = 0; i < 3; i++){
            if(board[i][k] == board[i+1][k]){
                return 1;
            }

        }
    }

    return 0;

}



void gameoverTer(){

    system("clear");
    printf("===== GAME OVER =====\n");
    printf("\nPress R to restart or Q to quit.\n");

    while(1){
        int choice = getchar();


        if(choice == 'R' || choice == 'r'){
            //resetGame();
            //gameOver = 0;
            return;
        }

        else if(choice == 's' || choice == 'q'){
            printf("bye bye wish you play again");
            exit(0);
        }
    }
}