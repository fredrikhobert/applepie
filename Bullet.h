#ifndef BULLET_H
#define BULLET_H

#include "SDL.h"
#include "Sprite.h"

class Bullet : public Sprite
{
public:

	Bullet(SDL_Rect);
	~Bullet();

	void updatePosition();
	void draw(SDL_Surface*);
	static void setBulletDirection(char);
	SDL_Rect* getRect();

private:

	SDL_Rect rect;
	bool active;
	int bulletVelocity;
	static char bulletDirection;
};

#endif