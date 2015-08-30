#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Sprite.h"
#include "Player.h"
#include "EnemyTypeOne.h"
#include "EnemyTypeTwo.h"
#include "Bullet.h"
#include "Events.h"
#include <iostream>
#include <string>

class GameEngine 
{

public:

	GameEngine();
	~GameEngine();

	void run();
	void addPlayer(std::string, bool);
	void addEnemyTypeOne(std::string, bool);
	void addEnemyTypeTwo(std::string, bool);
	void setWindowSize(int width, int height);
	void setBackground(std::string);
	void setFPS(int);
	void setEnemyTypeOneSettings(int, int, char);
	void setEnemyTypeTwoSettings(int, int, char);
	void setEnemysBeyondScreen(bool bs);
	void setText(std::string, int, int);
	void setPlayerSettings(char, bool, bool);
	void setStartScreenTxt(std::string);
	void setEndScreenTxt(std::string);
	void setFragScoreCounter(bool);
	void setEnemySpawnRate(int);
	void deleteSprite(int);
	void quitGame();
	
	bool SDL_SetUp();
	bool bulletCollision(SDL_Rect*);
	bool collisionCheck( SDL_Rect*, SDL_Rect*);	
	bool startGame(std::string);
	bool gameOver(std::string);
	
	static bool spriteBeyondWindow(Sprite *);	
	static int getWindowHeight();
	static int getWindowWidth();
	
	SDL_Surface* getWindow() const;

private:
	SDL_Surface* window;
	SDL_Surface* message;	
	SDL_Event event;

	Image background, typeOneEnemy, typeTwoEnemy;
	Player* player;

	std::vector<Sprite*> sprites;
	std::string endScreenText, startScreenText;
	
	static int windowWidth;
	static int windowHeight;
	
	int fps, startTicks, tick;
	int enemyDelay;
	int enemySpawnRate;
	int frags;
	int spriteOneLeft;
    int spriteOneRight;
    int spriteOneTop;
    int spriteOneBottom;
	int spriteTwoLeft;
	int spriteTwoRight;
	int spriteTwoTop;
	int spriteTwoBottom;
	
	bool beyondScreen;
	bool setCollition;
	bool fragScoreCounter;
	bool quit;
	
	void addEnemys();

};

#endif