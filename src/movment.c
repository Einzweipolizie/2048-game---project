#include <stdio.h>
#include "stdlib.h"


#include "header.h"



void slideX() {
    int arr[MAX_SIZE][MAX_SIZE] = {0};
    int tileSize = 60, gap = 2;

    for (int i = 0; i < boardsize; i++) {
        int pos = 0;
        for (int k = 0; k < boardsize; k++) {
            if (board[i][k] != 0) {
                arr[i][pos] = board[i][k];

                // Record animation target position for this tile
                tileAnim[i][k].targetPos.x = leftMargin + pos * (tileSize + gap);
                tileAnim[i][k].targetPos.y = topMargin  + i * (tileSize + gap);

                pos++;
            }
        }
    }

    // Copy back to board
    for (int i = 0; i < boardsize; i++) {
        for (int k = 0; k < boardsize; k++) {
            board[i][k] = arr[i][k];
        }
    }
}




void slideY() {
    int arr[MAX_SIZE][MAX_SIZE] = {0};
    int tileSize = 60, gap = 2;

    for (int k = 0; k < boardsize; k++) {
        int pos = 0;
        for (int i = 0; i < boardsize; i++) {
            if (board[i][k] != 0) {
                arr[pos][k] = board[i][k];

                // Record movement
                tileAnim[i][k].targetPos.x = leftMargin + k * (tileSize + gap);
                tileAnim[i][k].targetPos.y = topMargin  + pos * (tileSize + gap);

                pos++;
            }
        }
    }

    // Copy back
    for (int i = 0; i < boardsize; i++) {
        for (int k = 0; k < boardsize; k++) {
            board[i][k] = arr[i][k];
        }
    }
}


void merge(){

    for(int i = 0; i < boardsize; i++){
        for(int k = 0; k < boardsize - 1; k++){

            if(board[i][k] == board[i][k+1] && board[i][k] != 0){
                board[i][k] *= 2;
                board[i][k+1] = 0;
                score += board[i][k];
                audioEffect_merge();

            }


        }
    }
}

void mergecol(){
    for(int k = 0; k < boardsize; k++){
        for(int i = 0; i < boardsize - 1; i++){

            if(board[i][k] == board[i+1][k] && board[i][k] != 0){
                board[i][k] *= 2;
                board[i+1][k] = 0;
                score += board[i][k];
                audioEffect_merge();
            }


        }
    }    
    
}

void reverseRow(int row){

    for(int k = 0; k < boardsize / 2; k++){
        int tmp = board[row][k];
        board[row][k] = board[row][boardsize - 1 - k];
        board[row][boardsize - 1 - k] = tmp;

    }


}       

void reverseCol(int col) {
    for (int k = 0; k < boardsize / 2; k++) {
        int tmp = board[k][col];
        board[k][col] = board[boardsize - 1 - k][col];
        board[boardsize - 1 - k][col] = tmp;
    }
}