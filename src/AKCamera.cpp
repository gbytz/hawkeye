#include "AKCamera.h"
#include "AKScene.h"
#include "AKGameObject.h"


AKCamera::AKCamera()
{
	mState = CameraState::FIXED;
	mScene = NULL;
	mObject = NULL;
}

AKCamera::AKCamera(int x, int y, int w, int h, AKScene* scene)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	mState = CameraState::FIXED;
	mScene = scene;
	mObject = NULL;
}

AKCamera::~AKCamera()
{
	printf("AKCamera Destructor\n");
}

void AKCamera::update()
{
	switch(mState){
		case CameraState::FIXED:
		case CameraState::MOVINGTO:
			break;
		case CameraState::FOLLOWING:
            x = ( mObject->x + mObject->w / 2 ) - w / 2;
            y = ( mObject->y + mObject->h / 2 ) - h / 2;
            break;
        default:
        	break;
	}
    if( x < 0 ) x = 0;
    if( x > mScene->w - w ) x = mScene->w - w;
    if( y < 0 ) y = 0;
    if( y > mScene->h - h ) y = mScene->h - h;
}

void AKCamera::followObject(AKGameObject* object)
{
	mState = CameraState::FOLLOWING;
	mObject = object;
}