#include "raylib.h"
#include <unistd.h> // Required for sleep()


#include "header.h"



void rungameloop(){

    while(!WindowShouldClose()){

        
            raydrawboard();
            boardDrawing();
            if(!cantMove()){
                
                int result = gameoverRay();
                gameoverTer();

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


