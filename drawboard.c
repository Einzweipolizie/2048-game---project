
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "stdlib.h"


#include "header.h"

int getch(void) {
    struct termios oldt, newt;
    int button;
    tcgetattr(STDIN_FILENO, &oldt);              // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);            // disable buffering & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);     // apply new settings
    button = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);     // restore old settings
    return button;
}

int kbhit(void) {
    struct termios oldt, newt;
    int button;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    button = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (button != EOF) {
        ungetc(button, stdin);
        return 1;
    }

    return 0;
}

int board[4][4] = {0};

void boardDrawing(){

    char button; // what button pressed for dirictions
    int dir; // what diraction

    int arr[4][4];






        system("clear");

        for(int i = 0; i < 4; i++){ //   drawing board
            for(int k = 0; k <  4; k++){
                printf("%d ", board[i][k]);

            }
            printf("\n");
        }

        if(kbhit()){
            while (!kbhit()) {
                usleep(10000); // wait until a key is pressed
            }

            button = getch();

            if (button == 'a') dir = 1; // left
            else if (button == 'd') dir = 2; // right
            else if (button == 'w') dir = 3; // up
            else if (button == 's') dir = 4; // down
        }





        if(dir == 1){ // left
            slideX();
            merge();
            slideX();
            spawnTile();

        }

        if(dir == 2){  //right
            for(int i = 0; i < 4; i++){
                reverseRow(i);
            }
            slideX();
            merge();
            slideX();
            for(int i = 0; i < 4; i++){
                reverseRow(i);
            }
            spawnTile();

        }
        if(dir == 3){ // up
            slideY();      
            mergecol();    
            slideY();      
            spawnTile();

            
        }

        if(dir == 4){ // down
            for(int k = 0; k < 4; k++){
                reverseCol(k);
            }
            slideY();

                mergecol();
                slideY();
            for(int k = 0; k < 4; k++){
                reverseCol(k);
            }
            spawnTile();
            
        }





    

}



