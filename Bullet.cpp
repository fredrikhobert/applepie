#include "Bullet.h"


Bullet::Bullet(SDL_Rect pos)
{
	active = true;
	bulletVelocity = 20;
	rect.x = pos.x;
	rect.y = pos.y;
	rect.h = 15;
	rect.w = 10;
}

Bullet::~Bullet(){}
char Bullet::bulletDirection;

void Bullet::updatePosition()
{
	switch(bulletDirection)
	{
	case 'u': rect.y -= bulletVelocity; break;
	case 'd': rect.y += bulletVelocity; break;
	case 'l': rect.x -= bulletVelocity; break;
	case 'r': rect.x += bulletVelocity; break;
	}
}


void Bullet::draw(SDL_Surface* window)
{	
	updatePosition();
	SDL_FillRect(window , &rect , 0xFFFF66);	
}


SDL_Rect* Bullet::getRect()
{
	return &rect;
}


void Bullet::setBulletDirection(char dir)
{
	bulletDirection = dir;
}

