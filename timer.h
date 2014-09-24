#ifndef TIMER_H
#define TIMER_H

class Timer {

public:
    Timer();

    void start();

    Uint32 getTicks();

private:
    Uint32 startTicks;
    bool running;
};

#endif // TIMER_H