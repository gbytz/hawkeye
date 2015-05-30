#include "AKViewport.h"
#include "AKTexture.h"
#include "AKGameObject.h"

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
    mCamera = AKCamera(x, y, width, height, this);
    mBackgroundColor = {0, 0, 0};
}

AKViewport::~AKViewport()
{
    printf("AKViewport Destructor\n");
}

void AKViewport::update()
{
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->Update();
    }
    mCamera.update();
}

void AKViewport::render(SDL_Renderer* renderer, double delta)
{
    SDL_RenderSetViewport( renderer, &mView );
    SDL_RenderCopy( renderer, mBackgroundTexture->getTexture(), &mCamera, NULL );
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->Draw( &mCamera , delta );
    }
}

void AKViewport::setBackgroundColor(SDL_Color color)
{
    mBackgroundColor = color;
}

SDL_Color AKViewport::getBackgroundColor()
{
    return mBackgroundColor;
}

void AKViewport::setBackgroundTexture(AKTexture* texture)
{
    mBackgroundTexture = texture;
}

AKTexture* AKViewport::getBackgroundTexture()
{
    return mBackgroundTexture;
}

AKCamera* AKViewport::getCamera()
{
    return &mCamera;
}

unsigned int AKViewport::addObject(AKGameObject* object_pointer)
{
    unsigned int handle = mObjects.size();
    mObjects.push_back(object_pointer);
    return handle;
}

void AKViewport::removeObject(unsigned int object_id)
{
    mObjects.erase(mObjects.begin() + object_id);
}
