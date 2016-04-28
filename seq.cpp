#include <cstdlib>

#include "seq.h"

// - Seq ------------------------------------------------------------|
Event* Seq::addEvent(long n, long m, int ch) {
    delete events[n][m];
    events[n][m] = new Event(t+n, ch);
    return events[n][m];
};

long Seq::getN() { return N; };
long Seq::getM() { return M; };
long Seq::get_t() { return t; };

Event* Seq::getEvent(long n, long m) {
    if(n < N && n >= 0 && m < M && m >= 0)
        return events[n][m];
    else
        return NULL;
};

Seq::Seq(long t_t, long t_N, long t_M) {
    t = t_t;
    N = t_N;
    M = t_M;
    events = new Event**[N];
    for(long n=0; n<N; ++n) {
        events[n] = new Event*[M];
        for(long m=0; m<M; ++m)
            events[n][m] = NULL;
    };
}; 

Seq::~Seq() {
    for(long n=0; n<N; ++n) {
        for(long m=0; m<M; ++m)
            delete events[n][m];
        delete[] events[n];
    }
    delete[] events;
}; 
// ------------------------------------------------------------------|
// - Event ----------------------------------------------------------|
Event::Event(long t_t, int t_ch) {
    t = t_t;
    ch = t_ch;
};

int Event::get_ch() {
    return ch;
};

Event::~Event() {};

// ------------------------------------------------------------------|
