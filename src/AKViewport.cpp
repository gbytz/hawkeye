#include "AKViewport.h"

AKViewport::AKViewport(int width, int height)
{
    view.w = width;
    view.h = height;
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
