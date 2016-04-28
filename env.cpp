#include <ncurses.h>

#include "env.h"

// - Env -----------------------------------------------------------|
Env::Env(int t_x0, int t_y0) {
    x0 = t_x0;
    y0 = t_y0;
};

Env::~Env() {};
// -----------------------------------------------------------------|
// - seqEnv --------------------------------------------------------|
seqEnv::seqEnv(int t_x0, int t_y0, int t_w, int t_h) : Env(t_x0, t_y0) {
    w = t_w;
    h = t_h;
    win = newwin(h, w, y0, x0);    
    box(win, 0, 0);

    for(int y=1; y<h-1; y+=2) {
        for(int x=1; x<w-1; x+=2) {
            wmove(win, y, x);
            if(y == 1) {
                char buf[10];
                sprintf(buf, "%d", x/2 % 10);
                wprintw(win, buf);
            } else
                waddch(win, '|');
        }
    }
    
    wrefresh(win);
};

void seqEnv::drawSeq(Seq* seq) {
    long N = seq->getN();
    long M = seq->getM();

    int x_step = 2;
    int y_step = 2;
    
    Event* tempEvent;
    for(long n=0; n<N; ++n) {
        for(long m=0; m<M; ++m) {
            wmove(win, 1+m*y_step, n*x_step);
            tempEvent = seq->getEvent(n, m);
            if(tempEvent)   
               waddch(win, tempEvent->get_ch());
        };
    };
    wrefresh(win);
};

// -----------------------------------------------------------------|
