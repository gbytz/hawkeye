#ifndef AKSCENE_H
#define AKSCENE_H

// STL includes
#include <vector>

// Own libs
#include "AKViewport.h"

// Forwad declarations
class AKGameObject;


class AKScene : public AKViewport
{
	public:
		AKScene();
		~AKScene();

		void update();
		void render(SDL_Renderer* renderer, double delta);

		int w;
		int h;

        unsigned int addObject(AKGameObject* object_pointer);
        void removeObject(unsigned int object_handle);

	protected:
	private:	
        AKCamera mCamera;
        std::vector<AKGameObject*> mObjects;
};

#endif // AKSCENE_H