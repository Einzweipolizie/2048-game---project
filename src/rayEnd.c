#include "stdio.h"
#include "header.h"

// rayend.c
#include "raylib.h"
#include "header.h"

int gameoverRay() {
    SetTargetFPS(60);
    double starttime = 0;
    bool showbye = false;




    UnloadSound(bop);
    CloseAudioDevice();

    if(score > highscore){
        highscore = score;
        FILE *file = fopen("highscore.txt", "w");
        if(file != NULL){
            fprintf(file, "%d",highscore);
            fclose(file);
        }   
        else{
            printf("Error: could not save highscore!\n");
        }

    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (!showbye) {
            DrawText("YOU LOST YOU WERE NOT SO GOOD", 80, 300, 30, RED);
            DrawText("Press R to restart or Q to quit", 90, 350, 26, RED);

            if (IsKeyPressed(KEY_R)) { EndDrawing(); return 1; }
            if (IsKeyPressed(KEY_Q)) { showbye = true; starttime = GetTime(); }
        } else {
            DrawText("BYE BYE I WISH YOU WILL PLAY AGAIN", 80, 300, 30, RED);
            if (GetTime() - starttime >= 3.0) { EndDrawing(); return 0; }
            if (IsKeyPressed(KEY_R)) { EndDrawing(); return 1; }
        }

        EndDrawing();
    }
    return 0;
}
    


void resetgame(){

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    score = 0;
    spawnTile();
    spawnTile();

    
}