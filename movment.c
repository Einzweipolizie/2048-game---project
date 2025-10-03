#include <stdio.h>
#include "stdlib.h"


#include "header.h"



void slideX(){
    int arr[4][4] = {0};  // fresh array per move

    // slide each row
    for(int i = 0; i < 4; i++){
        int pos = 0;
        for(int k = 0; k < 4; k++){
            if(board[i][k] != 0){
                arr[i][pos] = board[i][k];
                pos++;
            }
        }
        while(pos < 4){
            arr[i][pos] = 0;
            pos++;
        }
    }



    // copy everything back to board after all rows are done
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            board[i][k] = arr[i][k];
        }
    }

}


void slideY(){
    int arr[4][4] = {0};

    for(int k = 0; k < 4; k++){     // col
        int pos = 0;
        for(int i = 0; i < 4; i++){ // row
            if(board[i][k] != 0){
                arr[pos][k] = board[i][k];
                pos++;
            }
        }
        while(pos < 4){
            arr[pos][k] = 0;
            pos++;
        }
    }
        // copy everything back to board after all rows are done
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 4; k++) {
                board[i][k] = arr[i][k];
            }
        }
}

void merge(){

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 3; k++){

            if(board[i][k] == board[i][k+1] && board[i][k] != 0){
                board[i][k] *= 2;
                board[i][k+1] = 0;
            }

        }
    }
}

void mergecol(){
    for(int k = 0; k < 4; k++){
        for(int i = 0; i < 3; i++){

            if(board[i][k] == board[i+1][k] && board[i][k] != 0){
                board[i][k] *= 2;
                board[i+1][k] = 0;
            }

        }
    }    
}

void reverseRow(int row){

    for(int k = 0; k < 2; k++){
        int tmp = board[row][k];
        board[row][k] = board[row][3-k];
        board[row][3-k] = tmp;

    }


}       

void reverseCol(int col) {
    for(int k = 0; k < 2; k++) {
        int tmp = board[k][col];
        board[k][col] = board[3-k][col];
        board[3-k][col] = tmp;
    }
}
