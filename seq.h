#ifndef SEQ_H_
#define SEQ_H_

class Seq;
class Event;

class Seq {
public:
    Seq(long t_t, long t_N, long t_M);
    ~Seq();

    Event* addEvent(long n, long m, int ch);
    Event* getEvent(long n, long m);

    long getN();
    long getM();
    long get_t();
private:
    long N, M, t;
    const char** tracknames;
    
    Event*** events;
    long eventCount;
};  // class Seq


class Event {
public:
    Event(long t_t, int t_ch);
    ~Event();
    void process();
    int get_ch();
private:
    long t;
    int ch;

};  // class Event
#endif
