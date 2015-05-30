#ifndef AKSCENE_H
#define AKSCENE_H

// Forward declaration
class AKViewport;


class AKScene : AKViewport
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