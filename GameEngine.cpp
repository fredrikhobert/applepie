#include "GameEngine.h"


GameEngine::GameEngine()
{
	windowWidth = 800; 
	windowHeight = 600;
	window = NULL;
	fps = 30;
	quit = false;
	enemyDelay = 0;
	enemySpawnRate = 2;
	frags = 0;
}


int GameEngine::windowWidth;
int GameEngine::windowHeight;


GameEngine::~GameEngine()
{
	for(int x=0; x < sprites.size(); x++)
		delete sprites[x];
	delete player;
}


void GameEngine::run()
{	
	startGame(startScreenText);
	while(!quit)
	{
		startTicks = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			Events::Events(&event, player);
			if(event.type == SDL_QUIT)
				quitGame();
		}

		SDL_BlitSurface(background.getSurface(), NULL, window, NULL);	
		player -> draw(window);

		// Om bullet kolliderar med fiendesprite
		for(int x=0; x < sprites.size(); x++)
		{						
			sprites[x] -> draw(window);			

			if(bulletCollision(sprites[x] -> getRect())){
				frags++;
				deleteSprite(x);
			}
		}

		// Om player kolliderar med fiendesprite
		if(setCollition){
			for(int x=0; x < sprites.size(); x++)
			{										
				if(collisionCheck(sprites[x] -> getRect(), player->getRect())){
					deleteSprite(x);;
					quit=true;
				}
			}}

		// Om fiendesprite rör sig utanför fönster
		for(int x=0; x < sprites.size(); x++)
		{	
			if(!beyondScreen){
				if(spriteBeyondWindow(sprites[x])){
					quit = true;
				}
			}
			if(spriteBeyondWindow(sprites[x])){
				deleteSprite(x);
			}
		}		

		if(fragScoreCounter){
			std::string fragStr = std::to_string(frags); 
			setText("score:" + fragStr, 1, 1);
		}

		addEnemys();
		SDL_Flip(window);

		tick = SDL_GetTicks() - startTicks;
		if(tick < 1000 / fps)
			SDL_Delay(1000 / fps - tick);
	}

	gameOver(endScreenText);
}


void GameEngine::addPlayer(std::string img, bool transparent)
{	
	Image playerImg(img, transparent);
	player = new Player(playerImg, 100, 100);
}


bool GameEngine::SDL_SetUp()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cerr << "Unable to initialize SDL";
		exit(-1);
	}

	window = SDL_SetVideoMode(windowWidth, windowHeight, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	if(window == NULL)
	{
		std::cerr << "Unable to set video mode";
		exit(-1);
	}

	if(TTF_Init() == -1)
	{
		std::cerr << "Unable to initialize TTF";
		exit(-1);;    
	}

	SDL_WM_SetCaption("SDL GAME", NULL);

	return true;
}


SDL_Surface* GameEngine::getWindow() const 
{ 
	return window; 
}


void GameEngine::setWindowSize(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
}


void GameEngine::setBackground(std::string bg)
{
	Image bgImg(bg, false);
	background = bgImg;
}


void GameEngine::setFPS(int x)
{
	fps = x;
}


void GameEngine::addEnemyTypeOne(std::string etoImg, bool transparent)
{
	Image toe(etoImg, transparent);	
	typeOneEnemy = toe;
}


void GameEngine::addEnemyTypeTwo(std::string etoImg, bool transparent)
{
	Image tte(etoImg, transparent);	
	typeTwoEnemy = tte;
}


void GameEngine::addEnemys()
{
	if(startTicks > enemyDelay){
		enemyDelay += 1000;

		for(int x=0; x < rand() % enemySpawnRate; x++)
		{
			Sprite* enemyTypeOne = new EnemyTypeOne(typeOneEnemy);
			sprites.push_back(enemyTypeOne);
			Sprite* enemyTypeTwo = new EnemyTypeTwo(typeTwoEnemy);
			sprites.push_back(enemyTypeTwo);
		}
	}
}


void GameEngine::setEnemyTypeOneSettings(int xVel, int yVel, char dir)
{
	EnemyTypeOne::setVelocity(xVel, yVel);
	EnemyTypeOne::setDirection(dir);
}


void GameEngine::setEnemyTypeTwoSettings(int xVel, int yVel, char dir)
{
	EnemyTypeTwo::setVelocity(xVel, yVel);
	EnemyTypeTwo::setDirection(dir);
}


void GameEngine::setEnemysBeyondScreen(bool bs)
{
	beyondScreen = bs;
}


void GameEngine::setPlayerSettings(char dir, bool coll, bool gun)
{
	Bullet::setBulletDirection(dir);
	player->setGun(gun);
	setCollition = coll;

}


bool GameEngine::bulletCollision(SDL_Rect* sprite)
{

	std::vector<Bullet*> bullets = player -> Player::getBullets();

	for(int x=0; x < bullets.size(); x++)
	{
		SDL_Rect* bullet = bullets[x] -> getRect();
		if(collisionCheck(sprite, bullet)){
			player -> Player::setBullets();
			return true;
		}

	}
	return false;
}


bool GameEngine::collisionCheck(SDL_Rect* spriteOne, SDL_Rect* spriteTwo)
{ 
	spriteOneLeft = spriteOne->x;
	spriteOneRight = spriteOne->x + spriteOne->w;
	spriteOneTop = spriteOne->y;
	spriteOneBottom = spriteOne->y + spriteOne->h;

	spriteTwoLeft = spriteTwo->x;
	spriteTwoRight = spriteTwo->x + spriteTwo->w;
	spriteTwoTop = spriteTwo->y;
	spriteTwoBottom = spriteTwo->y + spriteTwo->h;


	if(spriteOneRight <= spriteTwoLeft || spriteOneLeft >= spriteTwoRight)
	{
		return false;
	} 

	if(spriteOneBottom <= spriteTwoTop || spriteOneTop >= spriteTwoBottom)
	{
		return false;
	}

	return true;
}


bool GameEngine::spriteBeyondWindow(Sprite * sprite){

	SDL_Rect * r= sprite->getRect();

	if(r->y > windowHeight)
		return true;
	if(r->y < 0)
		return true;
	if(r->x > windowWidth)
		return true;
	if(r->x <= 0)
		return true;
	else
		return false;
}


bool GameEngine::startGame(std::string sst){

	SDL_BlitSurface(background.getSurface(), NULL, window, NULL);	
	setText(sst, GameEngine::getWindowWidth() / 3, GameEngine::getWindowHeight() / 2);
	SDL_Flip(window);

	bool f = false;
	while(!f){
		while(SDL_PollEvent(&event)){
			if(SDL_KEYDOWN){
				if(event.key.keysym.sym==SDLK_SPACE){
					frags = 0;	
					sprites.clear();
					quit=false;
					f=true;
				}
				if(event.type == SDL_QUIT)
					quitGame();
			}
		}
	}
	return false;
}


bool GameEngine::gameOver(std::string est){

	setText(est, GameEngine::getWindowWidth() / 3, GameEngine::getWindowHeight() / 2);
	bool f = false;
	while(!f){
		while(SDL_PollEvent(&event)){
			if(SDL_KEYDOWN){
				if(event.key.keysym.sym==SDLK_RETURN){
					player->resetVelocity();
					run();
				}
				if(event.type == SDL_QUIT)
					quitGame();
			}
		}
	}
	return false;
}


void GameEngine::setText(std::string msg, int xpos, int ypos)
{
	SDL_Rect offset = {xpos, ypos,0,0};
	TTF_Font* font = TTF_OpenFont("c:/windows/fonts/Verdana.ttf",26);
	SDL_Color white = {255,255,255};
	message = TTF_RenderText_Solid( font, msg.c_str(), white );
	SDL_BlitSurface(message, NULL, window, &offset);
	SDL_Flip(window);
}


void GameEngine::setStartScreenTxt(std::string sst)
{
	startScreenText = sst + ", press space to start!";
}


void GameEngine::setEndScreenTxt(std::string est)
{
	endScreenText = est + ", press retur to restart!";
}


void GameEngine::setFragScoreCounter(bool fsc)
{
	fragScoreCounter = fsc;
}


void GameEngine::setEnemySpawnRate(int esr)
{
	enemySpawnRate = esr;
}


int GameEngine::getWindowHeight()
{
	return windowHeight;
}


int GameEngine::getWindowWidth()
{
	return windowWidth;
}


void GameEngine::deleteSprite(int index)
{
	delete sprites[index];
	sprites.erase(sprites.begin()+index);
}


void GameEngine::quitGame()
{
	SDL_Quit();
	exit(0);
}