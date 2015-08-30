#include "Player.h"
#include "GameEngine.h"


Player::Player(Image img, int x=0, int y=0)
{
	image = img;
	player_Y_Velocity = 0;
	player_X_Velocity = 0;
	rect.x = GameEngine::getWindowWidth() / 2;
	rect.y = GameEngine::getWindowHeight() / 2;
}


Player::~Player()
{
	for(int x=0; x < bullets.size(); x++)
		delete bullets[x];
}


void Player::keyDown(int x)
{ 
	switch(x)
	{
	case ARROW_UP: player_Y_Velocity += 10; break;
	case ARROW_DOWN: player_Y_Velocity -= 10; break;
	case ARROW_RIGHT: player_X_Velocity += 10; break;
	case ARROW_LEFT: player_X_Velocity -= 10; break;
	case SPACE: addBullet(); break;
	}
}


void Player::keyUp(int x)
{
	switch(x)
	{
	case ARROW_UP: player_Y_Velocity -= 10; break;
	case ARROW_DOWN: player_Y_Velocity += 10; break;
	case ARROW_RIGHT: player_X_Velocity -= 10; break;
	case ARROW_LEFT: player_X_Velocity += 10; break;
	}
}


void Player::updatePosition()
{
	rect.x += player_X_Velocity;
	if(rect.x + rect.w > 1000)
		rect.x -= player_X_Velocity;

	rect.y -= player_Y_Velocity;
	if(rect.y + rect.h > 800)
		rect.y += player_Y_Velocity;
}


void Player::draw(SDL_Surface* window)

{	
	updatePosition();
	SDL_BlitSurface(image.getSurface(), NULL, window, &rect);	
	for(int x=0; x < bullets.size(); x++){

		if(GameEngine::spriteBeyondWindow(bullets[x])){
			delete bullets[x];
			bullets.erase(bullets.begin()+x);
		} else {bullets[x] -> draw(window);}
	}
}


void Player::addBullet()
{
	if(gunIsActive){
		Bullet* b = new Bullet(rect);
		bullets.push_back(b);
	}
}


std::vector<Bullet*> Player::getBullets()
{
	return bullets;
}


void Player::setBullets()
{
	bullets.clear();
}


SDL_Rect* Player::getRect()
{
	return &rect;
}


void Player::resetVelocity()
{
	player_Y_Velocity = 0;
	player_X_Velocity = 0;
}


void Player::setGun(bool gun)
{
	gunIsActive = gun;
}