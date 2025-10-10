#include "raylib.h"
#include <unistd.h> // Required for sleep()


#include "header.h"



void rungameloop(){

    while(!WindowShouldClose()){

        
            raydrawboard();
            boardDrawing();
            if(!cantMove()){
                gameoverRay();
                gameoverTer();
                break;
            }
            usleep(100000);  // small delay
    }

}


