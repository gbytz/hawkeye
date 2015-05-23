#ifndef AKVIEWPORT_H
#define AKVIEWPORT_H

// STL includes
#include <vector>

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKGameObject;


class AKViewport : public SDL_Rect
{
    public:
        AKViewport(int width, int height, int positionX, int positionY);
        ~AKViewport();

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();
    protected:
    private:
        SDL_Color mBackgroundColor;
};

#endif // AKVIEWPORT_H
