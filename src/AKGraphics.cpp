#include "AKGraphics.h"
#include "AKWindow.h"
#include "AKTexture.h"


AKGraphics::AKGraphics(AKWindow* window)
{
    mRenderer = window->getRenderer();
}

AKGraphics::~AKGraphics()
{
    printf("AKGraphics Destruct\n");
}

AKTexture* AKGraphics::loadFromFile( std::string imagePath )
{
    AKTexture* finalTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( imagePath.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
    }
    else
    {
//      //Color key image
//      SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        //Create texture from surface pixels
        SDL_Texture* newTexture = SDL_CreateTextureFromSurface( mRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError() );
        }
        else
        {
            finalTexture = new AKTexture(loadedSurface->w, loadedSurface->h, newTexture);
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return finalTexture;
}

AKTexture* AKGraphics::loadFromRenderedText( std::string textureText, std::string fontPath, int fontSize, SDL_Color textColor )
{
    AKTexture* finalTexture = NULL;

    //Open the font
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if( font == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Render text surface
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
        if( textSurface == NULL )
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface( mRenderer, textSurface );
            if( textTexture == NULL )
            {
                printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                finalTexture = new AKTexture(textSurface->w, textSurface->h, textTexture);
            }
            //Get rid of old surface
            SDL_FreeSurface( textSurface );
        }
    }
    return finalTexture;
}

void AKGraphics::render(AKTexture* texture, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, texture->getWidth(), texture->getHeight() };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( mRenderer, texture->getTexture(), clip, &renderQuad, angle, center, flip );
}
