#include "Sprite.h"
#include "GameEngine.h"


Sprite::Sprite(Image img)
{
	image = img;
}


Sprite::Sprite(){}
Sprite::~Sprite(){}
int Sprite::randomNr;


void Sprite::setImage(Image img)
{
	image = img;
}


int Sprite::get_X_Coordinate()
{
	randomNr = rand() % (GameEngine::getWindowWidth()-50);
	return randomNr;
}


int Sprite::get_Y_Coordinate()
{
	randomNr = rand() % (GameEngine::getWindowHeight()-50);
	return randomNr;
}


void Sprite::keyDown(int x){}
void Sprite::keyUp(int x){}

