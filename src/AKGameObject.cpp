#include "AKGameObject.h"
#include "AKGraphics.h"

unsigned int AKGameObject::COUNT = 0;

AKGameObject::AKGameObject()
{
    id = COUNT;
    COUNT++;
    x = 0;
    y = 0;
}

AKGameObject::~AKGameObject()
{
}
