#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Image
{
public:

	Image(std::string imageDirectory, bool transparent);
	Image();
	Image(const Image &);
	Image& operator=(const Image &);
	~Image();

	SDL_Surface* getSurface() const;
	void loadImage(std::string, bool);

private:

	SDL_Surface* image;
	bool transparent;
};



#endif