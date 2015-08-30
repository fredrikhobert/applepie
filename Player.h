#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

class Player : public Sprite
{
public:

	Player(Image, int, int);
	~Player();

	void keyUp(int x);
	void keyDown(int x);
	void updatePosition();
	void draw(SDL_Surface*);
	void addBullet();
	void setBullets();
	void resetVelocity();
	void setGun(bool);
	std::vector<Bullet*> getBullets();
	SDL_Rect* getRect();

private:

	SDL_Rect rect;
	std::vector<Bullet*> bullets;
	int player_X_Velocity;
	int player_Y_Velocity;
	bool gunIsActive;
	
	enum keyPresses
	{
		ARROW_UP,
		ARROW_DOWN,
		ARROW_RIGHT,
		ARROW_LEFT,
		SPACE
	};

};

#endif