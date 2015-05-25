// External libs
#include <SDL2/SDL.h>

// My libs
#include "AKEngine.h"
#include "AKWindow.h"
#include "AKGraphics.h"
#include "AKViewport.h"
#include "AKKeyboard.h"
#include "Player.h"

int main( int argc, char* args[] )
{
    AKEngine engine = AKEngine();
    if(!engine.start()){
        printf( "Failed to start engine!\n" );
    }
    else
    {
            bool quit = false;
            SDL_Event event;
            AKWindow* main_window = engine.window();
            AKGraphics graphics = AKGraphics(main_window);

            AKKeyboard keyboard = AKKeyboard();

            AKTexture* bgTexture = graphics.loadFromFile("../graphics/test.png");
            AKViewport view = AKViewport(0, 0, 640, 480);
            view.setBackgroundTexture(bgTexture);

            AKCamera* camera = view.getCamera();

            main_window->addViewport(&view);

            Player player = Player(0, 0);
            player.SetGraphicsComp(&graphics);
            player.SetKeyboardComp(&keyboard);

            view.addObject(&player);

            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &event ) != 0 )
                {
                    //User requests quit
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    main_window->handleEvent(event);
                }
                keyboard.Update();
                main_window->clear();
                main_window->update();
                camera->x = (player.x + 25) - 640 / 2;
                if( camera->x < 0 ) camera->x = 0;
                if( camera->x > 2560 - camera->w ) camera->x = 2560 - camera->w;
                main_window->render();
                main_window->present();
            }
    }
    engine.stop();
    return 0;
}
