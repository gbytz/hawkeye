#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

#include "AKTexture.h"

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
