#include "AKViewport.h"


unsigned int AKViewport::COUNT = 0;

unsigned int AKViewport::count(){
    return COUNT;
}

AKViewport::AKViewport(int x, int y, int width, int height)
{
    id = COUNT;
    COUNT++;
    mView.x = x;
    mView.y = y;
    mView.w = width;
    mView.h = height;
    mBackgroundColor = {0, 0, 0};
}

AKViewport::~AKViewport()
{
    printf("AKViewport Destructor\n");
}

void AKViewport::update()
{
}

void AKViewport::render(SDL_Renderer* renderer, double delta)
{
    SDL_RenderSetViewport( renderer, &mView );
    SDL_SetRenderDrawColor( renderer, mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a );
    SDL_RenderFillRect( renderer, &mView );
}

void AKViewport::setBackgroundColor(SDL_Color color)
{
    mBackgroundColor = color;
}

SDL_Color AKViewport::getBackgroundColor()
{
    return mBackgroundColor;
}
