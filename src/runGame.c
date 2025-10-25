#include"stdio.h"
#include "raylib.h"
#include <unistd.h> // Required for sleep()


#include "header.h"

Sound bop;
Sound thunder;
Sound nono;

int leftMargin;
int topMargin;

void rungameloop(){

    FILE *file = fopen("highscore.txt", "r");

    InitAudioDevice();
    bop = LoadSound("/home/david/Music/soundEffects/pop-402322.mp3");
    thunder = LoadSound("/home/david/Music/soundEffects/heavy-thunder-sound-338980.mp3");
    nono = LoadSound("/home/david/Music/soundEffects/no-x5-95904.mp3");


    if(file != NULL){
        fscanf(file, "%d", &highscore);
        fclose(file);
    }
    else{
        highscore = 0;
    }


    int gap = 2;
    int tileSize = 60;  
    int cellSize = tileSize + gap;


    int boardWidth = boardsize * tileSize + (boardsize - 1) * gap;
    int boardHeight = boardsize * tileSize + (boardsize - 1) * gap;


    leftMargin = (800 - boardWidth) / 2;
    topMargin = (600 - boardHeight) / 2;

    for (int i = 0; i < boardsize; i++) {
        for (int k = 0; k < boardsize; k++) {
            tileAnim[i][k].pos = tileAnim[i][k].targetPos =
                (Vector2){ leftMargin + k * (tileSize + gap),
                        topMargin + i * (tileSize + gap) };
        }
    }
    

    while(!WindowShouldClose()){

        
            raydrawboard();
            boardDrawing();
            if(!cantMove()){
                audioendgame_thunder();
                sleep(2);
                int result = gameoverRay();

                //gameoverTer();

                if(result == 1){
                    CloseAudioDevice();
                    CloseWindow();
                    restartprogram(); // Restarts the game completely
                    //continue;
                }
                else{
                    break;
                }
            }
            usleep(100000);  // small delay
    }

}


