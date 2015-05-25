#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes
#include <ostream>

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKGraphics;
class AKKeyboard;

typedef SDL_Rect AKCamera;


class AKGameObject
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKGameObject();
        virtual ~AKGameObject();
        virtual void Update() = 0;
        virtual void Draw(AKCamera* camera) = 0;

        void SetGraphicsComp(AKGraphics* graphics_comp);
        void SetKeyboardComp(AKKeyboard* keyboard_comp);

        // Members
        unsigned int id;
        int x;
        int y;

        int vX;
        int vY;
        // Friend methods
        friend std::ostream& operator<<(std::ostream& os, const AKGameObject& obj);

    protected:
        AKGraphics* mGraphics;
        AKKeyboard* mKeyboard;

    private:
        static unsigned int COUNT;
};

#endif // AKGAMEOBJECT_H
