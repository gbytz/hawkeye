#include "AKTimer.h"

AKTimer::AKTimer()
{
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void AKTimer::start()
{
    mStarted = true;
    mPaused = false;
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void AKTimer::stop()
{
    mStarted = false;
    mPaused = false;
	mStartTicks = 0;
	mPausedTicks = 0;
}

void AKTimer::pause()
{
    if( mStarted && !mPaused )
    {
        mPaused = true;
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

void AKTimer::unpause()
{
    if( mStarted && mPaused )
    {
        mPaused = false;
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint32 AKTimer::getTicks()
{
	Uint32 time = 0;
    if( mStarted )
    {
        if( mPaused )
        {

            time = mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - mStartTicks;
        }
    }
    return time;
}

bool AKTimer::isStarted()
{
    return mStarted;
}

bool AKTimer::isPaused()
{
    return mPaused && mStarted;
}