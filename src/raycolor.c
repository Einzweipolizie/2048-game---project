#include "raylib.h"

#include "header.h"



Color whatcolor(int value) {

    switch (value) {
        case 2: return LIGHTGRAY;
        case 4: return GRAY;
        case 8: return ORANGE;
        case 16: return RED;
        case 32: return BLACK;
        case 64: return MAGENTA;
        case 128: return PURPLE;
        default: return BLUE;
    }
}


