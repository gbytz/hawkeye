#ifndef AKVIEWPORT_H
#define AKVIEWPORT_H

// STL includes
#include <vector>

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKTexture;
class AKGameObject;

typedef SDL_Rect AKCamera;

class AKViewport : public SDL_Rect
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKViewport(int width, int height, int positionX, int positionY);
        ~AKViewport();

        void Update();
        void Render(SDL_Renderer* renderer);

        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundColor();

        void setBackgroundTexture(AKTexture* texture);
        SDL_Texture* getBackgroundTexture();

        AKCamera* getCamera();

        static unsigned int OBJECT_HANDLERS;
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
