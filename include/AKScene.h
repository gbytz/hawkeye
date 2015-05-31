#ifndef AKSCENE_H
#define AKSCENE_H

// STL includes
#include <vector>

// Own libs
#include "AKViewport.h"
#include "AKCamera.h"

// Forward declarations
class AKTexture;
class AKGameObject;


class AKScene : public AKViewport
{
	public:
		AKScene(int width, int height, int viewWidth, int viewHeight);
		~AKScene();

		void update();
		void render(SDL_Renderer* renderer, double delta);

		int w;
		int h;

        AKCamera* camera();

        void setBackgroundTexture(AKTexture* texture);
        AKTexture* getBackgroundTexture();

        unsigned int addObject(AKGameObject* object_pointer);
        void removeObject(unsigned int object_handle);

	protected:
	private:
	    AKTexture* mBackgroundTexture;

        AKCamera mCamera;
        std::vector<AKGameObject*> mObjects;
};

#endif // AKSCENE_H