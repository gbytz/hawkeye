#include "Player.h"
#include "AKGraphics.h"
#include "AKKeyboard.h"
#include "AKTexture.h"
#include "AKCamera.h"

#define PI 3.14159265

Player::Player(int x, int y) : AKGameObject()
{
    this->x = x;
    this->y = y;
    mTexture = NULL;
    shot = false;
    angle = -45;
}

Player::~Player()
{
}

void Player::update()
{
    if( !shot )
    {
        if( mKeyboard->LeftPressed() ) angle--;
        if( mKeyboard->RightPressed() ) angle++;
        if( mKeyboard->SpaceBarPressed() ){
            shot = true;
            double f = 50;
            vX = f * cos(angle * PI / 180.0);
            vY = f * sin(angle * PI / 180.0);
        }
    }
    x += vX;
    y += vY;
}

void Player::render(AKCamera* camera, double delta){
    SDL_Point point = { 0, mTexture->getHeight() / 2};
    mGraphics->render( mTexture, x - camera->x, y - camera->y, NULL, angle, &point);
}

void Player::setTexture(AKTexture* texture)
{
    mTexture = texture;
    w = texture->getWidth();
    h = texture->getHeight();
}