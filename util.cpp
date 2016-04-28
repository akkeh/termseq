#include <ncurses.h>

#include "util.h"

int clearcol(int x, int y0, int yN) {
    for(int y=y0; y<yN; ++y)
        mvaddch(y, x, ' ');
    return 0;
};  // clearline

int clearrow(int y, int x0, int xN) {
    for(int x=x0; x<xN; ++x)
        mvaddch(y, x, ' ');
    return 0;
};
