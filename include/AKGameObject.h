#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes
#include <ostream>

// Forward declarations
class AKGraphics;


class AKGameObject
{
    public:
        static unsigned int COUNT;

        AKGameObject();
        virtual ~AKGameObject();
        virtual void Draw() = 0;

        unsigned int id;
        int x;
        int y;

    protected:
        AKGraphics* mGraphics;

    private:
};

#endif // AKGAMEOBJECT_H
