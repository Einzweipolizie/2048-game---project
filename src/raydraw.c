#include "stdio.h"
#include "raylib.h"
#include "stdlib.h"
#include "unistd.h"

#include "header.h"

void raydrawboard(){
    
    int margin = 150;



            if(IsKeyPressed(KEY_A)){ // left
                slideX();
                merge();
                slideX();
                spawnTile();
        
        }
        if(IsKeyPressed(KEY_D)){ // right
            for(int i = 0; i < 4; i++){
                reverseRow(i);
            }
            slideX();
            merge();
            slideX();
            for(int i = 0; i < 4; i++){
                reverseRow(i);
            }
            spawnTile();
            
        }


        if(IsKeyPressed(KEY_W)){ // up
            slideY();      
            mergecol();    
            slideY();      
            spawnTile();
        
        }
        if(IsKeyPressed(KEY_S)){ // down
            for(int k = 0; k < 4; k++){
                reverseCol(k);
            }
            slideY();

                mergecol();
                slideY();
            for(int k = 0; k < 4; k++){
                reverseCol(k);
            }
            spawnTile();
        }


        BeginDrawing(); // need to do it ot start ding things
        ClearBackground(RAYWHITE); // the background

        for(int i = 0; i < 4; i++){
            for(int k = 0; k < 4; k++){

                int tileSize = 60;
                int gap = 2;
                int leftMargin = 277;
                int topMargin = 177;

                int x = leftMargin + (k * (tileSize + gap));   // k = col
                int y = topMargin + (i * (tileSize + gap));    // i = row
                DrawRectangleLines(x, y, 60, 60, ORANGE );

                if(board[i][k] != 0){

                    char buffer[100];
                    sprintf(buffer, "%d", board[i][k]);

                    DrawRectangle(x+3, y+3, 50, 50, BLUE);
                    DrawText(buffer, x+20, y+17, 28, RED);
                }
            }
        }




        EndDrawing(); // need to do it then you end
    }

        

    
