    #include "stdio.h"
    #include "raylib.h"
    #include "stdlib.h"
    #include "unistd.h"

    #include "header.h"


    int score;
    int highscore;
    static float animTime = 0.0f;          // how long animation has been running
    static float animDuration = 0.005;     // total animation time (in seconds)
    static bool isAnimating = false;       // are we currently animating?
    static bool needspawn = false;

    void raydrawboard(){
        
        int margin = 150;


            if(!isAnimating){
                if(IsKeyPressed(KEY_A)){ // left
                    beforeAnim();
                    slideX();   
                    merge();
                    slideX();
                    afteraAnim();
                    isAnimating = true;
                    animTime = 0.0f;
                    needspawn = true;

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
                    afteraAnim();
                    isAnimating = true;
                    animTime = 0.0f;
                    needspawn = true;

                }


                if(IsKeyPressed(KEY_W)){ // up
                    beforeAnim();
                    slideY();      
                    mergecol();    
                    slideY();      
                    afteraAnim();
                    isAnimating = true;
                    animTime = 0.0f;
                    needspawn = true;

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
                    afteraAnim();
                    isAnimating = true;
                    animTime = 0.0f;
                    needspawn = true;
                }
            }


            BeginDrawing(); // need to do it ot start ding things
            ClearBackground(RAYWHITE); // the background

            if(isAnimating){
                animTime += GetFrameTime();
                if(animTime >= animDuration){
                    animTime = animDuration;
                    isAnimating = false;
                    if (needspawn) {
                        spawnTile();
                        needspawn = false;
                    }
                }

            }

            float t = animTime / animDuration;  // goes from 0 → 1
            if (t >= 1.0f) {
                for (int i = 0; i < 4; i++) {
                    for (int k = 0; k < 4; k++) {
                        tileAnim[i][k].pos = tileAnim[i][k].targetPos;
                    }
                }
            }
            for(int i = 0; i < 4; i++){
                for(int k = 0; k < 4; k++){
                    int tileSize = 60;
                    int gap = 2;
                    int leftMargin = 277;
                    int topMargin = 177;
                    int x = leftMargin + k * (tileSize + gap);
                    int y = topMargin + i * (tileSize + gap);

                    DrawRectangleLines(x, y, 60, 60, ORANGE );



                    char highscorebuffer[100];
                    char scorebuffer[100];
                    sprintf(scorebuffer, "%d", score);
                    sprintf(highscorebuffer, "%d", highscore);

                    DrawText("your score is:   ",270,70, 30, RED);
                    DrawText(scorebuffer, 490,70, 30, RED); //score txt

                    DrawText("Best score:", 270, 110, 30, RED);
                    DrawText(highscorebuffer, 470, 110, 30, RED);
                    

                }
            }




            for(int i = 0; i < 4; i++){
                for(int k = 0; k < 4; k++){

                    int tileSize = 60;
                    int gap = 2;
                    int leftMargin = 277;
                    int topMargin = 177;

                    Vector2 base = tileAnim[i][k].basePos;
                    Vector2 target = tileAnim[i][k].targetPos;

                    float x = base.x + (target.x - base.x) * t;
                    float y = base.y + (target.y - base.y) * t;
                    
    

                    if(board[i][k] != 0){
                        Vector2 start = tileAnim[i][k].basePos;
                        Vector2 end = tileAnim[i][k].targetPos;

                        Vector2 pos;
                        pos.x = start.x + (end.x - start.x) * t;
                        pos.y = start.y + (end.y - start.y) * t;

                        Color dye = whatcolor(board[i][k]);
                        DrawRectangle(pos.x+3, pos.y+3, 50, 50, dye); // drawing the rectangle with color

                        char buffer[100];
                        sprintf(buffer, "%d", board[i][k]); // buffer is board
                        DrawText(buffer, pos.x+20, pos.y+17, 28, WHITE);


                        if (t == 1.0f) {
                            // Animation done → finalize positions
                            for (int i = 0; i < 4; i++) {
                                for (int k = 0; k < 4; k++) {
                                    tileAnim[i][k].pos = tileAnim[i][k].targetPos;
                                }
                            }
                        }

                    }
                }
            }




            EndDrawing(); // need to do it then you end
        }

            

        