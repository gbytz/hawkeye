#include "AKViewport.h"

AKViewport::AKViewport(int width, int height, int positionX, int positionY)
{
	w = width;
	h = height;
	x = positionX;
	y = positionY;
	mBackgroundColor = {0, 0, 0};
}

AKViewport::~AKViewport()
{
	printf("AKViewport Destructor\n");
}

void AKViewport::setBackgroundColor(SDL_Color color){
    mBackgroundColor = color;
}

SDL_Color AKViewport::getBackgroundColor(){
    return mBackgroundColor;
}
