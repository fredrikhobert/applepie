#include "EnemyTypeOne.h"
#include "GameEngine.h"

EnemyTypeOne::EnemyTypeOne(Image img)
{	
	image = img;	
	moveInDir(direction);
	moveVelocity(xVelocity, yVelocity);
}

EnemyTypeOne::~EnemyTypeOne(){}


int EnemyTypeOne::xVelocity;
int EnemyTypeOne::yVelocity;
char EnemyTypeOne::direction;


void EnemyTypeOne::updatePosition()
{
	rect.y += eto_Y_Velocity;
	rect.x += eto_X_Velocity;
}


void EnemyTypeOne::draw(SDL_Surface* window)
{
	updatePosition();
	SDL_BlitSurface(image.getSurface(), NULL, window, &rect);	
}


void EnemyTypeOne::setVelocity(int xVel, int yVel)
{
	xVelocity = xVel;
	yVelocity = yVel;
}


void EnemyTypeOne::setDirection(char dir)
{
	direction = dir;
}


void EnemyTypeOne::moveInDir(char dir)
{
	switch(dir)
	{
	case 't': rect.y = 0; rect.x = get_X_Coordinate(); break;
	case 'b': GameEngine::getWindowWidth(); rect.x = get_X_Coordinate(); break;
	case 'l': rect.y = get_X_Coordinate(); rect.x = 0; break;
	case 'r': rect.y = get_Y_Coordinate(); rect.x = GameEngine::getWindowHeight(); break;
	}
}


void EnemyTypeOne::moveVelocity(int xVel, int yVel)
{
	eto_X_Velocity = xVel;
	eto_Y_Velocity = yVel;
}


SDL_Rect* EnemyTypeOne::getRect()
{
	return &rect;
}