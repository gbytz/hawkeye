#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes
#include <ostream>

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
        virtual void Update() = 0;
        virtual void Draw(AKCamera* camera, double delta) = 0;

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
        // Friend methods
        friend std::ostream& operator<<(std::ostream& os, const AKGameObject& obj);

    protected:
        AKGraphics* mGraphics;
        AKKeyboard* mKeyboard;

    private:
        static unsigned int COUNT;
};

#endif // AKGAMEOBJECT_H
