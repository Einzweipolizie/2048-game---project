#include "raylib.h"

#include "header.h"


void gameoverRay(){

    InitWindow(800, 600, "GameOver"); //game over screen

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();

        DrawText("YOU LOST YOU WERE NOT SO GOOD", 60,300, 30, RED);




        EndDrawing();


    }

    CloseWindow();


}
