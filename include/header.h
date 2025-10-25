
#ifndef HEADER_H
#define HEADER_H


#include "raylib.h"

#define MAX_SIZE 20

extern int board[MAX_SIZE][MAX_SIZE];
extern int score;
extern int highscore;
extern int boardsize;
extern Sound bop;
extern Sound thunder;
extern Sound nono;

extern int leftMargin;
extern int topMargin;
// ================== STRUCTS ==================
typedef struct MovingTile {
    
    int value;
    Vector2 currentPos;
    Vector2 pos; // postion where the tile is now
    Vector2 basePos; // postion from where it will go
    Vector2 targetPos; // postion to where it will go
    bool merging;
    float progress;


}MovingTile;
 
extern MovingTile tileAnim[MAX_SIZE][MAX_SIZE];


//================animtion=========
void afteraAnim();
void beforeAnim();



void boardDrawing();

//==========boardsize=========
int startingMenu();

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

//sound
void audioEffect_merge();
void audiogame_nono();
void audioendgame_thunder();

int getch(void);

int kbhit(void);

//=======RESTART======
void restartprogram();

#endif