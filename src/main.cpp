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

            AKViewport view = AKViewport(640, 480, 0, 0);
            view.setBackgroundColor({ 0xFF, 0xFF, 0xFF });
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
                main_window->render();
                main_window->present();
            }
    }
    engine.stop();
    return 0;
}
