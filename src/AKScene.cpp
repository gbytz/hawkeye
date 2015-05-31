#include "AKScene.h"
#include "AKGameObject.h"
#include "AKTexture.h"

AKScene::AKScene(int width, int height, int viewWidth, int viewHeight) : AKViewport(0, 0, viewWidth, viewHeight)
{
    w = width;
    h = height;
    mCamera = AKCamera(0, 0, viewWidth, viewHeight, this);
    mBackgroundTexture = NULL;
}

AKScene::~AKScene()
{
    printf("AKScene Destructor\n");
}

void AKScene::update()
{
    AKViewport::update();
    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->update();
    }
    mCamera.update();
}

void AKScene::render(SDL_Renderer* renderer, double delta)
{
    AKViewport::render( renderer, delta );

    if(mBackgroundTexture != NULL)
    {
        SDL_RenderCopy( renderer, mBackgroundTexture->getTexture(), &mCamera, NULL );
    }

    for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
    {
        (*it)->render( &mCamera, delta );
    }
}

AKCamera* AKScene::camera()
{
    return &mCamera;
}

void AKScene::setBackgroundTexture(AKTexture* texture)
{
    mBackgroundTexture = texture;
}

AKTexture* AKScene::getBackgroundTexture()
{
    return mBackgroundTexture;
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