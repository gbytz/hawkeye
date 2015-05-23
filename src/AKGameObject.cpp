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
}

AKGameObject::~AKGameObject()
{
	printf("AKGameObject Destructor\n");
}

std::ostream& operator<<(std::ostream& os, const AKGameObject& obj)
{
    os << "id: " << obj.id << std::endl;
    os << "x: " << obj.x << std::endl;
    os << "y: " << obj.y << std::endl;
    return os;
}