#include "Player.h"
#include "AKGraphics.h"
#include "AKKeyboard.h"
#include "AKTexture.h"

#define PI 3.14159265

Player::Player(int x, int y) : AKGameObject()
{
    this->x = x;
    this->y = y;
    texture = NULL;
    shot = false;
    angle = -45;
}

Player::~Player()
{
}

void Player::Update()
{
    if( mKeyboard->LeftPressed() ) angle--;
    if( mKeyboard->RightPressed() ) angle++;

    if( !shot && mKeyboard->SpaceBarPressed() ){
        shot = true;
        double f = 50;
        vX = f * cos(angle * PI / 180.0);
        vY = f * sin(angle * PI / 180.0);
    }
    x += vX;
    y += vY;
}

void Player::Draw(AKCamera* camera){
    SDL_Point point = { 0, texture->getHeight() / 2};
    mGraphics->render( texture, x - camera->x, y - camera->y, NULL, angle, &point);
}