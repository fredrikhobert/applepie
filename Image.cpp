#include "Image.h"


Image::Image(std::string imageDirectory, bool transparent)
{
	loadImage(imageDirectory, transparent);
}


Image::Image(const Image &img)
{
	image = img.getSurface();
	if(image != 0)
		image -> refcount++;
}


Image& Image::operator=(const Image &img)
{
	
	if(this != &img){
		if(image != 0 && --image->refcount == 0)
			SDL_FreeSurface(image);
	image = img.getSurface();
	image -> refcount++;
	}
	return *this;
}


Image::Image()
{
	image = NULL;
}


Image::~Image()
{
	if(image != 0 && --image->refcount == 0)
		SDL_FreeSurface(image);
}


SDL_Surface* Image::getSurface() const
{
	return image;
}


void Image::loadImage(std::string imageDirectory, bool transparent)
{

	SDL_Surface* temp = IMG_Load(imageDirectory.c_str());

	if(temp != NULL)
	{		
		image = SDL_DisplayFormat(temp);
		SDL_FreeSurface(temp);
        if(transparent){
			Uint8 r, g, b;
			Uint32 *pixels = (Uint32 *)image->pixels;
			SDL_GetRGB(*pixels, image->format, &r, &g, &b );
			Uint32 color = SDL_MapRGB(image->format, r, g, b);
			SDL_SetColorKey(image, SDL_SRCCOLORKEY, color);
		}
		
		image -> refcount++;
		
	} else 
	{
		std::cout << "Image could not be loaded: " << SDL_GetError();
	}

}