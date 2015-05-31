#ifndef AKCAMERA_H
#define AKCAMERA_H

// Extermal libs
#include <SDL2/SDL.h>

// Forward declarations
class AKScene;
class AKGameObject;


class AKCamera : public SDL_Rect
{
	public:
		enum CameraState {
			FIXED,
			FOLLOWING,
			MOVINGTO
		};

		AKCamera();
		AKCamera(int x, int y, int w, int h, AKScene* scene);
		~AKCamera();

		void update();

		void followObject(AKGameObject* object);

	protected:

	private:
		CameraState mState;
		AKScene* mScene;
		AKGameObject* mObject;

};

#endif // AKCAMERA_H

