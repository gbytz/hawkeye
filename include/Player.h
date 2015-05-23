#ifndef PLAYER_H
#define PLAYER_H

#include "AKGameObject.h"

class Player : public AKGameObject
{
    public:
        Player(int x, int y);
        ~Player();
        void Draw();

    protected:
    private:
};

#endif // PLAYER_H
