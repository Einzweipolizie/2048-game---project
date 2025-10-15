#include "stdio.h"
#include "raylib.h"
#include "stdlib.h"
#include "unistd.h"
#include "math.h"

#include "header.h"

int score;

void raydrawboard(){
    
    int margin = 150;



        if(IsKeyPressed(KEY_A)){ // left
            beforeAnim();
            slideX();   
            merge();
            slideX();
            spawnTile();
            afteraAnim();

    
        }
        if(IsKeyPressed(KEY_D)){ // right
            beforeAnim();
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
            afteraAnim();
            
        }


        if(IsKeyPressed(KEY_W)){ // up
            beforeAnim();
            slideY();      
            mergecol();    
            slideY();      
            spawnTile();
            afteraAnim();

        }
        if(IsKeyPressed(KEY_S)){ // down
            beforeAnim();
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
            afteraAnim();

        }


        BeginDrawing(); // need to do it ot start ding things
        ClearBackground(RAYWHITE); // the background



        for(int i = 0; i < 4; i++){
            for(int k = 0; k < 4; k++){

                MovingTile *t = &tileanim[i][k];

                if(t ->active){
                    float targetX = 277 + t->toCol * 62;
                    float targetY = 177 +t->toRow * 62;

                    t->x += (targetX - t->x) * 0.3f;
                    t->y += (targetY - t->y) * 0.3f;

                    if (fabs(t->x - targetX) < 1 && fabs(t->y - targetY) < 1) {
                        t->active = false;

                }
                int tileSize = 60;
                int gap = 2;
                int leftMargin = 277;
                int topMargin = 177;

                int x = leftMargin + (k * (tileSize + gap));   // k = col
                int y = topMargin + (i * (tileSize + gap));    // i = row
                DrawRectangleLines(t->x, t->y, 60, 60, ORANGE );

                char scorebuffer[100];
                sprintf(scorebuffer, "%d", score);
                DrawText("your score is:   ",270,70, 30, RED);
                DrawText(scorebuffer, 490,70, 30, RED); //score txt

                if(board[i][k] != 0){
                    Color dye = whatcolor(board[i][k]);

                    char buffer[100];
                    sprintf(buffer, "%d", board[i][k]); // buffer is board

                    DrawRectangle(x+3, y+3, 50, 50, dye); // drawing the rectangle with color
                    DrawText(buffer, x+20, y+17, 28, WHITE);
                }
            }
        }




        EndDrawing(); // need to do it then you end
    }
}

        

    
