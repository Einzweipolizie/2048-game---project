#include "raylib.h"

#include "header.h"




MovingTile tileAnim[4][4];


void beforeAnim(){

    int tileSize = 60;
    int gap = 2;
    int leftMargin = 277;
    int topMargin = 177;






    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){

            if(board[i][k] != 0){
                tileAnim[i][k].basePos = tileAnim[i][k].pos;
            }

        }
    }
}







void afteraAnim(){

    int tileSize = 60;
    int gap = 2;
    int leftMargin = 277;
    int topMargin = 177;


    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){

            if(board[i][k] != 0){
                tileAnim[i][k].targetPos = (Vector2){
                    leftMargin + k * (tileSize  + gap),
                    topMargin + i * (tileSize + gap)
                };
            }

        }
    }


}