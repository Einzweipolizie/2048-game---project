#include "stdio.h"
#include <stdlib.h>

#include "header.h"

void spawnTile(){

    int empty[16][2];
    int count = 0;


    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            if(board[i][k] == 0){
                empty[count][0] = i;
                empty[count][1] = k;
                count++;
            }

        }
    }

    if(count == 0)return; //no space left

    int r = rand() % count;
    int value = (rand() % 10 == 0) ? 4 : 2;
    board[empty[r][0]][empty[r][1]] = value;


}