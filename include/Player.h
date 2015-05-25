#ifndef PLAYER_H
#define PLAYER_H

#include "AKGameObject.h"

class Player : public AKGameObject
{
    public:
        Player(int x, int y);
        ~Player();

        void Update();
        void Draw(AKCamera* camera);

    protected:
    private:
};

#endif // PLAYER_H
