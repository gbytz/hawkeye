#ifndef PLAYER_H
#define PLAYER_H

#include "AKGameObject.h"

class AKTexture;

class Player : public AKGameObject
{
    public:
        Player(int x, int y);
        ~Player();

        void update();
        void render(AKCamera* camera, double delta);

        void setTexture(AKTexture *);


    protected:
    private:
        bool shot;
        AKTexture* mTexture;
};

#endif // PLAYER_H
