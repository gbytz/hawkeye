#ifndef AKWINDOW_H
#define AKWINDOW_H

#include <sstream>
#include <vector>

#include <SDL2/SDL.h>

#include "AKViewport.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class AKWindow
{
	public:
		//Intializes internals
		AKWindow();
        ~AKWindow();

		bool init(); //Creates window

		void handleEvent( SDL_Event& e );   //Handles window events
		void focus();   //Focuses on window
		void clear();   // Clears the screen
        void update();  //Shows windows contents

		void free(); //Deallocates internals

		//Window dimensions
		int getWidth();
		int getHeight();

        SDL_Renderer* getRenderer();

		//Window focii
		bool hasMouseFocus();
		bool hasKeyboardFocus();
		bool isMinimized();
		bool isShown();

		// Viewports methods
		static unsigned int VIEWPORTS;
		unsigned int addViewport(AKViewport* viewport);
		void removeViewport(unsigned int viewport_id);

	private:
		//Window data
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		unsigned int mWindowID;
        std::stringstream mCaption;

		//Window dimensions
		int mWidth;
		int mHeight;

		//Window focus
		bool mMouseFocus;
		bool mKeyboardFocus;
		bool mFullScreen;
		bool mMinimized;
		bool mShown;

		//Window viewports
		std::vector<AKViewport*> mViewports;
};


#endif // AKWINDOW_H
