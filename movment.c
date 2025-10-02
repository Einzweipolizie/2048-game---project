#include <stdio.h>
#include "stdlib.h"


#include "header.h"



void slide_left(){
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

void merge_left(){

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 3; k++){

            if(board[i][k] == board[i][k+1] && board[i][k] != 0){
                board[i][k] *= 2;
                board[i][k+1] = 0;
            }

        }
    }

    
}

void reverse(){

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 3; k++){
            
        }
    }


}       
