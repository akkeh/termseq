#include <cstring>
#include <ncurses.h>

#include "definputs.h"
#include "input.h"
#include "util.h"
#include "cmnd.h"

int cmnd(int ch) {
        clearrow(CMNDROW, 0, 90);
        mvaddch(CMNDROW, 0, ch);
        echo();
        char inp[90];
        getstr(inp);
       
        if(std::strcmp(inp, "q") == 0) {
            return 0;
        } else{
            printw(inp);
            return 1;
        };
};  // cmnd()

