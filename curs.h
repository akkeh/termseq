#include <ncurses.h>

#include "input.h"

enum modes { cmnd, edit };

class Curs{
    int x, y;
    int mode;
    WINDOW* fWin;   // the focused window

};  //  class Curs
