#include "stdio.h"
#include "stdlib.h"


#include "header.h"

int board[4][4] = {0};

void boardDrawing(){

    char button; // what button pressed for dirictions
    int dir; // what diraction

    int random1 = (rand() % 4);
    int random2 = (rand() % 4);

    int mainNum = (rand() % 2);
    if(mainNum == 1){
        mainNum = 2;
    }
    else{
        mainNum = 4;
    }


    board[random1][random2] = mainNum;


    for(int i = 0; i < 4; i++){ //   drawing board
        for(int k = 0; k <  4; k++){
            printf("%d ", board[i][k]);

        }
        printf("\n");
    }

        if(kbhit()){
            button = getch();

            if (button == 'a') dir = 1; // left
            else if (button == 'd') dir = 2; // right
            else if (button == 'w') dir = 3; // up
            else if (button == 's') dir = 4; // down
        }

        if(dir == 1){ // left
            for(int i = 0; i < 4; i++){
                
            }
        }


}



int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);              // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);            // disable buffering & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);     // apply new settings
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);     // restore old settings
    return ch;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}