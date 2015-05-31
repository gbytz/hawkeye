#ifndef AKVIEWPORT_H
#define AKVIEWPORT_H

// STL includes
// External libs
#include <SDL2/SDL.h>

// Own libs
// Forward declarations


class AKViewport
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKViewport(int x, int y, int width, int height);
        ~AKViewport();

        virtual void update();
        virtual void render(SDL_Renderer* renderer, double delta);

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();

        // Members
        unsigned int id;

    protected:
        SDL_Rect mView;
        SDL_Color mBackgroundColor;

    private:
        static unsigned int COUNT;
};

#endif // AKVIEWPORT_H
