#ifndef ENEMYTYPEONE_H
#define ENEMYTYPEONE_H

#include "Sprite.h"

class EnemyTypeOne : public Sprite
{
public:

	EnemyTypeOne(Image);
	~EnemyTypeOne();

	void updatePosition();
	void draw(SDL_Surface*);
	static void setVelocity(int, int);
	static void setDirection(char);
	SDL_Rect* getRect();

private:

	SDL_Rect rect;
	int eto_Y_Velocity;
	int eto_X_Velocity;
	static int yVelocity;
	static int xVelocity;
	static char direction;

	void moveInDir(char);
	void moveVelocity(int, int);

};


#endif