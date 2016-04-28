#include <cstdlib>
#include <ncurses.h>

#include "env.h"
#include "seq.h"

int main() {
    // window stuff
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    int w, h;
    getmaxyx(stdscr, h, w);

    refresh();    
    Env* subEnv = new seqEnv(0.1 * w, 0.1 * h, 4*16, 8);

    getch();
    Seq* seq = new Seq(0, 16, 2);
    for(int i=0; i<16*2; i++) {
        seq->addEvent(std::rand() % 16, std::rand() % 2, (int)'x');
       
    };
    ((seqEnv*)subEnv)->drawSeq(seq);

    getch();
    endwin();

    delete seq;
};
