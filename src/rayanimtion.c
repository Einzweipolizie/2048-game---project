#include "raylib.h"

#include "header.h"




MovingTile tileanim[4][4];


void beforeAnim(){

    
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            tileanim[i][k].value = board[i][k];
            tileanim[i][k].fromRow = i;
            tileanim[i][k].fromCol = k;
            tileanim[i][k].active = false;
        }
    }


}


void afteraAnim(){



    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            int value = board[i][k];

            if (value != 0){
                tileanim[i][k].toRow = i;
                tileanim[i][k].toCol = k;
                tileanim[i][k].value = value;


                tileanim[i][k].x = 277 + tileanim[i][k].fromCol * 62;
                tileanim[i][k].y = 277 + tileanim[i][k].fromRow * 62;


                tileanim[i][k].active = true;

            }

        }
    }


}