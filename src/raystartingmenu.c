
#include "stdio.h"
#include "raylib.h"

int startingMenu(){

    InitWindow(800, 600, "selcet border size");
    SetTargetFPS(60);

    Rectangle buttons[4] = {
        {300, 200, 200, 50}, // 2x2
        {300, 270, 200, 50}, // 3x3
        {300, 340, 200, 50}, // 4x4
        {300, 410, 200, 50}  // 5x5
    };

        while(!WindowShouldClose()){
            BeginDrawing();
            ClearBackground(BLACK);

            for(int i = 0; i < 4; i++){
                DrawRectangleRec(buttons[i], WHITE);
                DrawText((i==0)?"2x2":(i==1)?"3x3":(i==2)?"4x4":"5x5", 350, 210 + i*70, 30, BLACK);
            }
        
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                Vector2 mouse = GetMousePosition();
                for(int i = 0; i < 4; i++){
                    if(CheckCollisionPointRec(mouse, buttons[i])){
                        int boardsize = i + 2;
                        CloseWindow();
                        return boardsize;
                    }
                }
            }
         EndDrawing();
        }
    CloseWindow();
    return 4;
}
