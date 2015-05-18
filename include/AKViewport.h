#ifndef AKVIEWPORT_H
#define AKVIEWPORT_H

#include <SDL2/SDL.h>

class AKViewport
{
    public:
        AKViewport(int width, int height);
        virtual ~AKViewport();
    protected:
    private:
        SDL_Rect view;
};

#endif // AKVIEWPORT_H
