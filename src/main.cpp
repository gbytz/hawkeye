// External libs
#include <SDL2/SDL.h>

// My libs
#include "AKEngine.h"
#include "AKWindow.h"
#include "AKGraphics.h"
#include "AKViewport.h"

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
			SDL_Color green = { 0x00, 0xFF, 0x00 };
			SDL_Color blue = { 0x00, 0x00, 0xFF };

			AKViewport view1 = AKViewport(50, 50, 50, 50);
			view1.setBackgroundColor(red);

			AKViewport view2 = AKViewport(100, 100, 250, 200);
			view2.setBackgroundColor(green);

			AKViewport view3 = AKViewport(100, 100, 300, 250);
			view3.setBackgroundColor(blue);

			main_window->addViewport(&view1);
			main_window->addViewport(&view2);
			unsigned int view3_id = main_window->addViewport(&view3);

			unsigned long step = 0;
			int SHAKE = 5;
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
				switch( step % 4 ){
					case 0:
						view1.x += SHAKE;
						break;
					case 1:
						view1.y += SHAKE;
						break;
					case 2:
						view1.x -= SHAKE;
						break;
					case 3:
						view1.y -= SHAKE;

						break;
				}
				main_window->update();
				++step;
				if( step == 100 ){
					main_window->removeViewport(view3_id);
				}
			}
	}
	engine.stop();
	return 0;
}
