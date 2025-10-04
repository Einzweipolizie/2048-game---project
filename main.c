#include "raylib.h"
#include <unistd.h>
#include "time.h"

#include "header.h"

int main() {
    //srand(time(NULL));

    spawnTile();
    spawnTile();


    while(1){
    boardDrawing();
    usleep(100000);  // small delay
    }

    return 0;
}
