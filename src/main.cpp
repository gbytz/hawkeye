#include "AKEngine.h"
#include "AKGraphics.h"
#include <SDL2/SDL.h>

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

            AKTexture* test = graphics.loadFromFile("../graphics/test.png");

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
