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
	if(mKeyboard->UpPressed()) y -= 10;
	if(mKeyboard->DownPressed()) y += 10;
	if(mKeyboard->LeftPressed()) x -= 10;
	if(mKeyboard->RightPressed()) x += 10;
}

void Player::Draw(){
	SDL_Color blue = { 0x00, 0x00, 0xFF, 0xFF };
	mGraphics->DrawRectangle(x, y, 50, 50, blue);
}