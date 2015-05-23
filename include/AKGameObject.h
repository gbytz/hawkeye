#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H

// STL includes
#include <ostream>

// Forward declarations
class AKGraphics;


class AKGameObject
{
    public:
        // Class methods
        unsigned int count();

        // Instance methods
        AKGameObject();
        virtual ~AKGameObject();
        virtual void Draw() = 0;

        void SetGraphicsComp(AKGraphics* graphics_comp);

        // Members
        unsigned int id;
        int x;
        int y;

        // Friend methods
        friend std::ostream& operator<<(std::ostream& os, const AKGameObject& obj);

    protected:
        AKGraphics* mGraphics;

    private:
        static unsigned int COUNT;
};

#endif // AKGAMEOBJECT_H
