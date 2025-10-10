
#ifndef HEADER_H
#define HEADER_H


#include "raylib.h"



extern int board[4][4];
extern int score;


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


// Raylib
void raydrawboard();
void gameoverRay();
void rungameloop();
Color whatcolor(int value);


int getch(void);

int kbhit(void);

#endif