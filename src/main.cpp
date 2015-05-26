// External libs
#include <SDL2/SDL.h>

// My libs
#include "AKEngine.h"
#include "AKWindow.h"
#include "AKGraphics.h"
#include "AKViewport.h"
#include "AKKeyboard.h"
#include "AKTexture.h"
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

            AKTexture* bgTexture = graphics.loadFromFile("../graphics/background.png");
            AKTexture* arrow = graphics.loadFromFile("../graphics/arrow.png");


            AKViewport view = AKViewport( 0, 0, main_window->getWidth(), main_window->getHeight() );
            view.setBackgroundTexture( bgTexture );
            main_window->addViewport( &view );

            AKCamera* camera = view.getCamera();
            camera->y = view.getBackgroundTexture()->getHeight() - camera->h;

            AKKeyboard keyboard = AKKeyboard();

            Player player = Player(5, view.getBackgroundTexture()->getHeight() - arrow->getHeight() - 5 );
            player.SetGraphicsComp(&graphics);
            player.SetKeyboardComp(&keyboard);
            player.texture = arrow;

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
                camera->x = ( player.x + arrow->getWidth() / 2 ) - camera->w / 2;
                camera->y = ( player.y + arrow->getHeight() / 2 ) - camera->h / 2;
                if( camera->x < 0 ) camera->x = 0;
                if( camera->x > bgTexture->getWidth() - camera->w ) camera->x = bgTexture->getWidth() - camera->w;
                if( camera->y < 0 ) camera->y = 0;
                if( camera->y > bgTexture->getHeight() - camera->h ) camera->y = bgTexture->getHeight() - camera->h;
                main_window->render();
                main_window->present();
            }
    }
    engine.stop();
    return 0;
}
