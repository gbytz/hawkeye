#include "AKTexture.h"

AKTexture::AKTexture( int width, int height, SDL_Texture* texture )
{
	//Initialize
	mTexture = texture;
	mWidth = width;
	mHeight = height;
}

AKTexture::~AKTexture()
{
	//Deallocate
	free();
}

void AKTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
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

int AKTexture::getWidth()
{
	return mWidth;
}

int AKTexture::getHeight()
{
	return mHeight;
}

SDL_Texture* AKTexture::getTexture()
{
    return mTexture;
}
