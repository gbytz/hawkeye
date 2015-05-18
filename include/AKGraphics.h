#ifndef AKGRAPHICS_H
#define AKGRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "AKWindow.h"
#include "AKTexture.h"
#include "AKGameObject.h"

class AKGraphics
{
    public:
        AKGraphics( AKWindow* window );
        ~AKGraphics();

        AKTexture* loadFromFile( std::string path );
        AKTexture* loadFromRenderedText( std::string textureText, std::string fontPath, int fontSize, SDL_Color textColor );

        void renderObject(const AKGameObject& object);
		//Renders texture at given point
		void render( AKTexture* texture, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    protected:
    private:
        SDL_Renderer* mRenderer;
};

#endif // AKGRAPHICS_H
