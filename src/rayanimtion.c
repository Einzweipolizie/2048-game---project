#include "raylib.h"

#include "header.h"




MovingTile tileAnim[MAX_SIZE][MAX_SIZE];


void beforeAnim() {
    int tileSize = 60;
    int gap = 2;
    int leftMargin = 277;
    int topMargin = 177;

    for (int i = 0; i < boardsize; i++) {
        for (int k = 0; k < boardsize; k++) {
            tileAnim[i][k].basePos.x = leftMargin + k * (tileSize + gap);
            tileAnim[i][k].basePos.y = topMargin  + i * (tileSize + gap);
        }
    }
}






void afteraAnim() {
    int tileSize = 60;
    int gap = 2;
    int leftMargin = 277;
    int topMargin = 177;

    for (int i = 0; i < boardsize; i++) {
        for (int k = 0; k < boardsize; k++) {
            tileAnim[i][k].targetPos.x = leftMargin + k * (tileSize + gap);
            tileAnim[i][k].targetPos.y = topMargin  + i * (tileSize + gap);
        }
    }
}



