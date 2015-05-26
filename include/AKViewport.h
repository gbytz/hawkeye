#ifndef AKVIEWPORT_H
#define AKVIEWPORT_H

// STL includes
#include <vector>

// External libs
#include <SDL2/SDL.h>

// Own libs
#include "AKCamera.h"

// Forward declarations
class AKTexture;
class AKGameObject;


class AKViewport
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKViewport(int x, int y, int width, int height);
        ~AKViewport();

        void Update();
        void Render(SDL_Renderer* renderer);

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();

        void setBackgroundTexture(AKTexture* texture);
        AKTexture* getBackgroundTexture();

        AKCamera* getCamera();

        unsigned int addObject(AKGameObject* object_pointer);
        void removeObject(unsigned int object_handle);

        // Members
        unsigned int id;

    protected:
    private:
        static unsigned int COUNT;

        AKCamera mView;
        SDL_Color mBackgroundColor;
        AKTexture* mBackgroundTexture;

        AKCamera mCamera;
        std::vector<AKGameObject*> mObjects;
};

#endif // AKVIEWPORT_H
