#include "Player.h"
#include "AKGraphics.h"
#include "AKKeyboard.h"

Player::Player(int x, int y) : AKGameObject()
{
    this->x = x;
    this->y = y;
}

Player::~Player()
{
}

void Player::Update()
{
    vY = (mKeyboard->UpPressed()) ? -10:0;
    vY += (mKeyboard->DownPressed()) ? 10:0;
    vX = (mKeyboard->LeftPressed()) ? -10:0;
    vX += (mKeyboard->RightPressed()) ? 10:0;

    x += vX;
    if( x < 0 || x + 50 > 2560) x -= vX;

    y += vY;
    if( y < 0 || y + 50 > 480) y -= vY;
}

void Player::Draw(AKCamera* camera){
    SDL_Color blue = { 0x00, 0x00, 0xFF, 0xFF };
    mGraphics->DrawRectangle( x - camera->x, y - camera->y, 50, 50, blue );
}