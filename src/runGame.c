#include"stdio.h"
#include "raylib.h"
#include <unistd.h> // Required for sleep()


#include "header.h"

Sound bop;
int leftMargin;
int topMargin;

void rungameloop(){

    FILE *file = fopen("highscore.txt", "r");

    InitAudioDevice();
    bop = LoadSound("/home/david/Music/soundEffects/pop-402322.mp3");

    if(file != NULL){
        fscanf(file, "%d", &highscore);
        fclose(file);
    }
    else{
        highscore = 0;
    }

    int screenWidth = 800;
    int screenHeight = 600;
    int tileSize = 60;
    int gap = 2;
    int cellSize = tileSize + gap;

    leftMargin = (screenWidth  - boardsize * cellSize) / 2;
    topMargin  = (screenHeight - boardsize * cellSize) / 2;

    for (int i = 0; i < boardsize; i++)
        for (int k = 0; k < boardsize; k++)
            tileAnim[i][k].pos = tileAnim[i][k].targetPos =
                (Vector2){ leftMargin + k * cellSize, topMargin + i * cellSize };


    

    while(!WindowShouldClose()){

        
            raydrawboard();
            boardDrawing();
            if(!cantMove()){
                
                int result = gameoverRay();
                //gameoverTer();

                if(result == 1){
                    resetgame();
                    continue;
                }
                else{
                    break;
                }
            }
            usleep(100000);  // small delay
    }

}


