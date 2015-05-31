#include "AKTexture.h"

AKTexture::AKTexture( int width, int height, SDL_Texture* texture )
{
	//Initialize
	mTexture = texture;
	w = width;
	h = height;
}

AKTexture::~AKTexture()
{
	//Deallocate
	free();
}

void AKTexture::free()
{
	printf("AKTexture Destructor\n");
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		w = 0;
		h = 0;
	}
}

void AKTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void AKTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void AKTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

SDL_Texture* AKTexture::getTexture()
{
    return mTexture;
}
