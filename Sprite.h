#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"
#include <iostream>
#include "SDL.h"

class Sprite
{

public:

	Sprite();
	Sprite(Image);
	~Sprite();

	void setImage(Image);
	virtual SDL_Rect* getRect()=0;

	virtual void draw(SDL_Surface*)=0;
	virtual void keyDown(int x);
	virtual void keyUp(int x);

protected:

	Image image;
	static int get_X_Coordinate();
	static int get_Y_Coordinate();
	static int randomNr;

};

#endif
