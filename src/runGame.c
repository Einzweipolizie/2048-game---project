#include"stdio.h"
#include "raylib.h"
#include <unistd.h> // Required for sleep()


#include "header.h"

Sound bop;

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


