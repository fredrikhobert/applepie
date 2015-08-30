#include "GameEngine.h"


int main( int argc, char* args[] )
{
	GameEngine ge;

	// S�tt storlek p� f�nster
	ge.setWindowSize(1000, 800);
	
	// S�tt uppdateringsfrekvens
	ge.setFPS(100);
	
	// Starta SDL och subsystem
	ge.SDL_SetUp();

	// S�tt bakgrund f�r spelplan
	ge.setBackground("bg.png");	

	// L�gg till spelarobjekt
	ge.addPlayer("player.png", true);

	// L�gg till fiendeobjekt
	ge.addEnemyTypeOne("enemy.png", true);

	// L�gg till ett andra fiendeobjekt
	ge.addEnemyTypeTwo("enemy2.png", true);

	// Text f�r startGame()
	ge.setStartScreenTxt("Hello :)");

	// R�knar antalet terminerade fiender
	ge.setFragScoreCounter(true);

	// Skjutriktning, (u=up, d=down, l=left, r=right)
	// Kolliderar med andra objekt 
	// Skjuta av/p�
	ge.setPlayerSettings('r', true, true);

	// Hastighet i x-led, 
	// Hastighet i y-led, 
	// Startsida, (t=top, b=bottom, l=left, r=right)
	ge.setEnemyTypeOneSettings(-3, 0, 'r');
	ge.setEnemyTypeTwoSettings(0, 4, 't');

	// Tempo f�r att l�gga till fiender, h�gra tal -> mer fiender
	ge.setEnemySpawnRate(2);

	// Fiender kan passera genom spelf�nstret 
	ge.setEnemysBeyondScreen(true);

	// Text for gameOver()
	ge.setEndScreenTxt("GAME OVER");

	ge.run();


	return 0;
}

