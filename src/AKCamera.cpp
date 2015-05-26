#include "AKCamera.h"
#include "AKGameObject.h"
#include "AKViewport.h"
#include "AKTexture.h"

AKCamera::AKCamera()
{
	mState = CameraState::FIXED;
	mViewport = NULL;
	mObject = NULL;
}

AKCamera::AKCamera(int x, int y, int w, int h, AKViewport* viewport)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	mViewport = viewport;
}

AKCamera::~AKCamera()
{
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
            if( x < 0 ) x = 0;
            if( x > mViewport->getBackgroundTexture()->getWidth() - w ) x = mViewport->getBackgroundTexture()->getWidth() - w;
            if( y < 0 ) y = 0;
            if( y > mViewport->getBackgroundTexture()->getHeight() - h ) y = mViewport->getBackgroundTexture()->getHeight() - h;
            break;
        default:
        	break;
	}
}

void AKCamera::followObject(AKGameObject* object)
{
	mState = CameraState::FOLLOWING;
	mObject = object;
}