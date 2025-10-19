#include "raylib.h"

#include "header.h"




MovingTile tileAnim[4][4];


void beforeAnim() {
    int tileSize = 60;
    int gap = 2;
    int leftMargin = 277;
    int topMargin = 177;

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
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

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            tileAnim[i][k].targetPos.x = leftMargin + k * (tileSize + gap);
            tileAnim[i][k].targetPos.y = topMargin  + i * (tileSize + gap);
        }
    }
}



