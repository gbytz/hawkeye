#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKGraphics;
class AKKeyboard;
class AKCamera;

class AKGameObject
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKGameObject();
        virtual ~AKGameObject();
        virtual void update() = 0;
        virtual void render(AKCamera* camera, double delta) = 0;

        void setGraphicsComp(AKGraphics* graphics_comp);
        void setKeyboardComp(AKKeyboard* keyboard_comp);

        // Members
        unsigned int id;
        int x;
        int y;
        int w;
        int h;

        int vX;
        int vY;

        double angle;

    protected:
        AKGraphics* mGraphics;
        AKKeyboard* mKeyboard;

    private:
        static unsigned int COUNT;
};

#endif // AKGAMEOBJECT_H
