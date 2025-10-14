
#ifndef HEADER_H
#define HEADER_H


#include "raylib.h"



extern int board[4][4];
extern int score;

// ================== STRUCTS ==================
typedef struct MovingTile {
    int value;
    int fromRow, fromCol;
    int toRow, toCol;
    float x, y;
    bool active;

}MovingTile;



void boardDrawing();


//movements
void slideX(); // slide left function
void merge(); // merge from the left
void reverseRow(int row);
void slideY();
void reverseCol(int col);
void mergecol();

void spawnTile(); // tile spawner

int cantMove(); // game over function and cheks if needs to end the game
void gameoverTer();
void resetgame();

// Raylib
void raydrawboard();
int gameoverRay();
void rungameloop();
Color whatcolor(int value);
void ryebye();


int getch(void);

int kbhit(void);

#endif