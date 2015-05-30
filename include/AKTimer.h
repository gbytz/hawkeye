#ifndef AKTIMER_H
#define AKTIMER_H

// External libs
#include <SDL2/SDL.h>


class AKTimer
{
    public:
        AKTimer();

        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 getTicks();

        bool isStarted();
        bool isPaused();

    private:
        Uint32 mStartTicks;
        Uint32 mPausedTicks;

        bool mPaused;
        bool mStarted;
};

#endif // AKTIMER_H