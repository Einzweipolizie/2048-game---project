#include "stdio.h"
#include "raylib.h"
#include <unistd.h>
#include "time.h"
#include "stdlib.h"

#include "header.h"

int main() {
    srand(time(NULL));

    spawnTile();
    spawnTile();


    while(1){
    raydrawboard();
    boardDrawing();
    if(!cantMove()){
       gameover();
    }
    usleep(100000);  // small delay
    }

    return 0;
}
