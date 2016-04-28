#ifndef ENV_H_
#define ENV_H_

#include <ncurses.h>

#include "seq.h"

class Env {
public:
    Env(int t_x0, int t_y0);
    ~Env();
protected:
    int x0, y0, w, h;
    WINDOW* win;
};  // class Env

class seqEnv : public Env {
public:
    seqEnv(int t_x0, int t_y0, int t_w, int t_h);
    void drawSeq(Seq* seq);

    ~seqEnv();
private:


};

#endif
