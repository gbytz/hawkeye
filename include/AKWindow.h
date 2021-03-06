#ifndef AKWINDOW_H
#define AKWINDOW_H

// STL includes
#include <sstream>
#include <vector>

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKViewport;


class AKWindow
{
    public:
        //Intializes internals
        AKWindow();
        ~AKWindow();

        bool init(); //Creates window

        void handleEvent( SDL_Event& e );   //Handles window events
        void focus();   // Focuses on window
        void clear();   // Clears the screen
        void update();	// Update window viewports
        void render(double delta);  // Render window contents
        void present(); // Shows window contents

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
        unsigned int addViewport(AKViewport* viewport);
        void removeViewport(unsigned int viewport_handle);

    private:
        static const int SCREEN_WIDTH = 1280;
        static const int SCREEN_HEIGHT = 720;

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
