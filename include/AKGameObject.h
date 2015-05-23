#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes
#include <ostream>

// Forward declarations
class AKGraphics;


class AKGameObject
{
    friend class AKGraphics;
    public:
        static unsigned int COUNT;

        AKGameObject();
        virtual ~AKGameObject();

        unsigned int id;
        int x;
        int y;

    protected:
        AKTexture* sprite;

    private:
};

#endif // AKGAMEOBJECT_H
