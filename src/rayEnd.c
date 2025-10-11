#include "raylib.h"

#include "header.h"


void gameoverRay(){

    InitWindow(800, 600, "GameOver"); //game over screen

    SetTargetFPS(60);


    bool showbye = false;
    double starttime = 0;

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK);

        if(!showbye){
        DrawText("YOU LOST YOU WERE NOT SO GOOD", 80,300, 30, RED);
        DrawText("Press R to restart or Q to quit", 90, 350, 26, RED);
        


            if(IsKeyPressed(KEY_Q)){
                showbye = true;
                starttime = GetTime();
                
            }
        }
        
        else{
            DrawText("BYE BYE I WISH YOU WILL PLAY AGAIN", 80, 300, 30, RED);
            
            if(GetTime() - starttime >= 5.0){
                break;
            }
        }


        EndDrawing();


    }

    CloseWindow();


}
