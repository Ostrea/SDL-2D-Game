#include <SDL/SDL_timer.h>
#include "timer.h"

Timer::Timer() {
    startTicks = 0;
    pausedTicks = 0;
    running = false;
}

void Timer::start() {
    running = true;
    startTicks = SDL_GetTicks();
}

Uint32 Timer::getTicks() {
    return running ? SDL_GetTicks() - startTicks : pausedTicks;
}

void Timer::pause() {
    if (running) {
        running = false;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause() {
    if (!running) {
        running = true;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}
