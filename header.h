#ifndef HEADER_H
#define HEADER_H




extern int board[4][4];


void boardDrawing();


//movements
void slideX(); // slide left function
void merge(); // merge from the left
void reverseRow(int row);
void slideY();
void reverseCol(int col);
void mergecol();

#endif