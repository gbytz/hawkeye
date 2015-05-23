// External libs
#include <SDL2/SDL.h>

// My libs
#include "AKEngine.h"
#include "AKWindow.h"
#include "AKGraphics.h"
#include "AKViewport.h"
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

            SDL_Color red = { 0xFF, 0x00, 0x00 };

            AKViewport view = AKViewport(400, 300, 0, 0);
            view.setBackgroundColor(red);
            main_window->addViewport(&view);

            Player player = Player(0, 0);
            player.SetGraphicsComp(&graphics);

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
                main_window->clear();
                main_window->update();
            }
    }
    engine.stop();
    return 0;
}
