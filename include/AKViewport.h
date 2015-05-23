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
        // Class methods
        unsigned int count();

        // Instance methods
        AKViewport(int width, int height, int positionX, int positionY);
        ~AKViewport();

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();
    protected:
    private:
        static unsigned int COUNT;
        SDL_Color mBackgroundColor;
};

#endif // AKVIEWPORT_H
