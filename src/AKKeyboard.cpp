#include "AKKeyboard.h"

AKKeyboard::AKKeyboard()
{
}

AKKeyboard::~AKKeyboard()
{
}

void AKKeyboard::Update()
{
	currentKeyStates = SDL_GetKeyboardState( NULL );
}

bool AKKeyboard::UpPressed()
{
	return currentKeyStates[SDL_SCANCODE_UP];
}

bool AKKeyboard::DownPressed()
{
	return currentKeyStates[SDL_SCANCODE_DOWN];
}

bool AKKeyboard::LeftPressed()
{
	return currentKeyStates[SDL_SCANCODE_LEFT];
}

bool AKKeyboard::RightPressed()
{
	return currentKeyStates[SDL_SCANCODE_RIGHT];
}

bool AKKeyboard::SpaceBarPressed()
{
	return currentKeyStates[SDL_SCANCODE_SPACE];
}