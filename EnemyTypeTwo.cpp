#include "EnemyTypeTwo.h"
#include "GameEngine.h"

EnemyTypeTwo::EnemyTypeTwo(Image img)
{	
	image = img;	
	moveInDir(direction);
	moveVelocity(xVelocity, yVelocity);
}

EnemyTypeTwo::~EnemyTypeTwo(){}


int EnemyTypeTwo::xVelocity;
int EnemyTypeTwo::yVelocity;
char EnemyTypeTwo::direction;


void EnemyTypeTwo::updatePosition()
{
	rect.y += ett_Y_Velocity;
	rect.x += ett_X_Velocity;
}


void EnemyTypeTwo::draw(SDL_Surface* window)
{
	updatePosition();
	SDL_BlitSurface(image.getSurface(), NULL, window, &rect);	
	SDL_Surface*tmp = image.getSurface();
	std::cout << "enemy 2: " << tmp->refcount;
	std::cout << "";
}


void EnemyTypeTwo::setVelocity(int xVel, int yVel)
{
	xVelocity = xVel;
	yVelocity = yVel;
}


void EnemyTypeTwo::setDirection(char dir)
{
	direction = dir;
}


void EnemyTypeTwo::moveInDir(char dir)
{
	switch(dir)
	{
	case 't': rect.y = 0; rect.x = get_X_Coordinate(); break;
	case 'b': rect.y = GameEngine::getWindowHeight(); rect.x = get_X_Coordinate(); break;
	case 'l': rect.y = get_X_Coordinate(); rect.x = 0; break;
	case 'r': rect.y = get_Y_Coordinate(); rect.x = GameEngine::getWindowWidth(); break;
	}
}


void EnemyTypeTwo::moveVelocity(int xVel, int yVel)
{
	ett_X_Velocity = xVel;
	ett_Y_Velocity = yVel;
}


SDL_Rect* EnemyTypeTwo::getRect()
{
	return &rect;
}