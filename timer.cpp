#include <SDL/SDL_timer.h>
#include "timer.h"

Timer::Timer() {
    startTicks = 0;
    running = false;
}

void Timer::start() {
    running = true;
    startTicks = SDL_GetTicks();
}

Uint32 Timer::getTicks() {
    return running ? SDL_GetTicks() - startTicks : 0;
}
