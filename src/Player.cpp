#include "Player.h"
#include "AKGraphics.h"

Player::Player(int x, int y) : AKGameObject()
{
	this->x = x;
	this->y = y;
}

Player::~Player()
{
}

void Player::Draw(){
	SDL_Color blue = { 0x00, 0x00, 0xFF, 0xFF };
	mGraphics->DrawRectangle(x, y, 50, 50, blue);
}