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
