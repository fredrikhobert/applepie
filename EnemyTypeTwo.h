#ifndef ENEMYTYPETWO_H
#define ENEMYTYPETWO_H

#include "Sprite.h"

class EnemyTypeTwo : public Sprite
{
public:

	EnemyTypeTwo(Image);
	~EnemyTypeTwo();

	void updatePosition();
	void draw(SDL_Surface*);
	static void setVelocity(int, int);
	static void setDirection(char);
	SDL_Rect* getRect();

private:

	SDL_Rect rect;
	int ett_Y_Velocity;
	int ett_X_Velocity;
	static int yVelocity;
	static int xVelocity;
	static char direction;

	void moveInDir(char);
	void moveVelocity(int, int);

};


#endif