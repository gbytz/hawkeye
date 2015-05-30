#include "AKScene.h"

void AKScene::update() : update()
{
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->Update();
    }
    mCamera.update();
}

void AKScene::render(SDL_Renderer* renderer, double delta) : render()
{
    SDL_RenderCopy( renderer, mBackgroundTexture->getTexture(), &mCamera, NULL );
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->Draw( &mCamera , delta );
    }
}

unsigned int AKScene::addObject(AKGameObject* object_pointer)
{
    unsigned int handle = mObjects.size();
    mObjects.push_back(object_pointer);
    return handle;
}

void AKScene::removeObject(unsigned int object_id)
{
    mObjects.erase(mObjects.begin() + object_id);
}