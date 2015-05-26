#ifndef PLAYER_H
#define PLAYER_H

#include "AKGameObject.h"

class AKTexture;

class Player : public AKGameObject
{
    public:
        Player(int x, int y);
        ~Player();

        void Update();
        void Draw(AKCamera* camera);

        AKTexture* texture;

    protected:
    private:
        bool shot;
};

#endif // PLAYER_H
