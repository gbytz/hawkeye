#include "AKScene.h"
#include "AKGameObject.h"
#include "AKTexture.h"

void AKScene::update()
{
    AKViewport::update();
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->Update();
    }
    mCamera.update();
}

void AKScene::render(SDL_Renderer* renderer, double delta)
{
    AKViewport::render( renderer, delta );
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