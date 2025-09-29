#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Raylib Test");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 350, 280, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
