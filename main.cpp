#include <ncurses.h>

#include "input.h"

int main() {
    int ch;
    int h, w;

    initscr();  //  start curses mode
    raw();      //  disable line buffering (Ctrl+c/z are passed to
                //      programm, w/o generating a signal
    keypad(stdscr, TRUE);   // grab F1, F2, tec.
    noecho();   // don't print while getch();

    getmaxyx(stdscr, h, w);
    // attron(A_STANDOUT);
    
  
    ch = -999; 
    while(getinput(ch)) {
        ch = getch();
    } 
    endwin();   // end curses mode

    return 0;
};  // main()
