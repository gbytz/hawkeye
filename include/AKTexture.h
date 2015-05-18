#ifndef AKTEXTURE_H
#define AKTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class AKTexture
{
	public:
		//Initializes variables
		AKTexture(int width, int height, SDL_Texture* texture);

		//Deallocates memory
		~AKTexture();

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Gets image dimensions
		int getWidth();
		int getHeight();
		SDL_Texture* getTexture();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

#endif // AKTEXTURE_H
