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

        void Update();
        void Render();

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();


        static unsigned int OBJECT_HANDLERS;
        unsigned int addObject(AKGameObject* object_pointer);
        void removeObject(unsigned int object_handle);

        // Members
        unsigned int id;

    protected:
    private:
        static unsigned int COUNT;
        SDL_Color mBackgroundColor;
        std::vector<AKGameObject*> mObjects;
};

#endif // AKVIEWPORT_H
