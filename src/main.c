#include "stdio.h"
#include "raylib.h"
#include <unistd.h>
#include "time.h"
#include "stdlib.h"

#include "header.h"

int boardsize;

int main() {
    srand(time(NULL));

    boardsize = startingMenu();

    for(int i = 0; i < boardsize; i++)
        for(int k = 0; k < boardsize; k++)
            tileAnim[i][k].pos = tileAnim[i][k].targetPos = (Vector2){277 + k*62, 177 + i*62};


    InitWindow(800, 600, "2048");
    SetTargetFPS(60);


    spawnTile();
    spawnTile();



    beforeAnim();
    afteraAnim();

    
    rungameloop();

    

    CloseWindow();

    return 0;
}
