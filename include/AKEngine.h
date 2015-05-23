#ifndef AKENGINE_H
#define AKENGINE_H

// External libs
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Forward declarations
class AKWindow;


class AKEngine
{
    public:
        AKEngine();
        ~AKEngine();

        bool start();
        void stop();

        AKWindow* window();

    protected:
    private:
        AKWindow* mWindow;
};

#endif // AKENGINE_H
