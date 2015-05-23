#include "AKViewport.h"
#include "AKGameObject.h"

unsigned int AKViewport::COUNT = 0;
unsigned int AKViewport::OBJECT_HANDLERS = 0;

unsigned int AKViewport::count(){
    return COUNT;
}

AKViewport::AKViewport(int width, int height, int positionX, int positionY)
{
    id = COUNT;
    COUNT++;
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

void AKViewport::Render(){
	for (std::vector<AKGameObject*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
	{
		(*it)->Draw();
	}
}

void AKViewport::setBackgroundColor(SDL_Color color){
    mBackgroundColor = color;
}

SDL_Color AKViewport::getBackgroundColor(){
    return mBackgroundColor;
}

unsigned int AKViewport::addObject(AKGameObject* object_pointer){
    unsigned int handle = OBJECT_HANDLERS;
    mObjects.push_back(object_pointer);
    ++OBJECT_HANDLERS;
    return handle;
}

void AKViewport::removeObject(unsigned int object_id){
    mObjects.erase(mObjects.begin() + object_id);
}
