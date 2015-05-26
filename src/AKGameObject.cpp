#include "AKGameObject.h"
#include "AKGraphics.h"

unsigned int AKGameObject::COUNT = 0;

unsigned int AKGameObject::count()
{
    return COUNT;
}

AKGameObject::AKGameObject()
{
    id = COUNT;
    COUNT++;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    vX = 0;
    vY = 0;
    angle = 0;
    mGraphics = NULL;
    mKeyboard = NULL;
}

AKGameObject::~AKGameObject()
{
    printf("AKGameObject Destructor\n");
}

void AKGameObject::setGraphicsComp(AKGraphics* graphics_comp)
{
    mGraphics = graphics_comp;
}

void AKGameObject::setKeyboardComp(AKKeyboard* keyboard_comp)
{
    mKeyboard = keyboard_comp;
}
