#include <ncurses.h>

#include "curs.h"

class Env {
public:
    Evn();
    ~Env();

private:
    int x0, y0, // anchor co-ordinates
    int w, h;   // width, height

    Curs* lastCurs; // remember last cursor on this screen
};  // class Env

class mainEnv : public Env {
/*  main: stdscr, contains other screens:
        ---------------------------------
        | subscrtitle(seq/comp)         |
        | ---------------------------   |
        | | subscr                  |   |
        | ---------------------------   |
        | :cmnd line                    |
        ---------------------------------                       */ 
public:
    mainEnv();  // create compEnv
private:
    Env* subEnv;

};  // class mainEnv

class compEnv : public Env {
/*  comp: contains seqs, allows moving of seqs and setting of loop
            points.
        --------------------------------
        |          *(start)  +(stop)   | (loop)
        |          0====1====2====3=   | (bars)
        | tr0ctrl [                 ]  | (track0)
        | tr1ctrl [                 ]  | (track1)
        | tr2ctrl [                 ]  | (track2)
        --------------------------------                        */
public:
    Env* addSeq();   // add a sequence

private:
    seqEnv* seqs;   // sequences

};  // class compEnv

class seqEnv : public Env {
/*  seq: editing of sequence
        ---------------------------------
        | sequence info                 |
        | [1| |1| | |1| |1|1| |1| |1| ] | ('note'-numbers)
        | [2| |3| |2| | | |3| |4| |1| ] |
        | [ | | | | | | | | | | | | | ] |
        ---------------------------------                       */  
public:
    addEvent(); // add event

private:
    Event* events;  // events
};  // class seqEnv
