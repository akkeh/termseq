#include <ncurses.h>

#include "definputs.h"
#include "input.h"
#include "cmnd.h"
#include "util.h"


int getinput(int ch) {
    switch(ch) {
        case COLON:
            return cmnd(ch);
            break;
        case (int)'i':
            printw("edit mode!\n");
            break;
        case ESC:
            printw("command mode!\n");
            break;
        default:
            printw("char: %c\t=num: %d\n", ch, ch);
            break;
    };
    return 1;
};  // getinput();

int mvcur(int ch) {

};  // mvcur();
