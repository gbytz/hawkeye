#ifndef AKGRAPHICS_H
#define AKGRAPHICS_H

// STL includes
#include <string>

// External libs
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Forward declarations
class AKWindow;
class AKTexture;


class AKGraphics
{
    public:
        // Instance methods
        AKGraphics( AKWindow* window );
        ~AKGraphics();

        AKTexture* loadFromFile( std::string path );
        AKTexture* loadFromRenderedText( std::string textureText, std::string fontPath, int fontSize, SDL_Color textColor );

        //Renders texture at given point
        void render( AKTexture* texture, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        void DrawRectangle(int x, int y, int width, int height, SDL_Color color);

    protected:
    private:
        SDL_Renderer* mRenderer;
};

#endif // AKGRAPHICS_H
