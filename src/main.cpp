// External libs
#include <SDL2/SDL.h>

// My libs
#include "AKEngine.h"
#include "AKWindow.h"
#include "AKGraphics.h"
#include "AKViewport.h"
#include "AKKeyboard.h"
#include "AKTexture.h"
#include "AKTimer.h"
#include "Player.h"


int main( int argc, char* args[] )
{
    AKEngine engine = AKEngine();
    if( !engine.start() ){
        printf( "Failed to start engine!\n" );
    }
    else
    {
            double MS_PER_UPDATE = 15.0;
            bool quit = false;
            SDL_Event event;
            AKWindow* main_window = engine.window();
            AKGraphics graphics = AKGraphics(main_window);

            AKTexture* bgTexture = graphics.loadFromFile("../graphics/background.png");
            AKTexture* arrow = graphics.loadFromFile("../graphics/arrow.png");

            AKViewport view = AKViewport( 0, 0, main_window->getWidth(), main_window->getHeight() );
            view.setBackgroundTexture( bgTexture );
            main_window->addViewport( &view );

            AKKeyboard keyboard = AKKeyboard();

            Player player = Player( 5, view.getBackgroundTexture()->getHeight() - arrow->getHeight() - 5 );
            player.setGraphicsComp( &graphics );
            player.setKeyboardComp( &keyboard );
            player.setTexture( arrow );

            view.addObject( &player );

            AKCamera* camera = view.getCamera();
            camera->followObject( &player );
           
            AKTimer timer = AKTimer();
            timer.start();
            double lag = 0.0;
            double previous = timer.getTicks();

            while( !quit )
            {
                double current = timer.getTicks();
                double elapsed = current - previous;
                previous = current;
                lag += elapsed;
                
                // Handl input
                while( SDL_PollEvent( &event ) != 0 )
                {
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    main_window->handleEvent(event);
                }
                keyboard.Update();

                // Update
                while( lag >= MS_PER_UPDATE ){
                    main_window->update();
                    lag -= MS_PER_UPDATE;
                }

                // Render
                main_window->render( lag / MS_PER_UPDATE );
            }
    }
    engine.stop();
    return 0;
}
