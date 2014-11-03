#ifndef TIMER_H
#define TIMER_H

class Timer {

public:
    Timer();

    void start();

    Uint32 getTicks();

    void pause();

    void unpause();

private:
    Uint32 startTicks;
    Uint32 pausedTicks;
    bool running;
};

#endif // TIMER_H