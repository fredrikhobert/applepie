#include "GameEngine.h"


int main( int argc, char* args[] )
{
	GameEngine ge;

	// Sätt storlek på fönster
	ge.setWindowSize(1000, 800);
	
	// Sätt uppdateringsfrekvens
	ge.setFPS(100);
	
	// Starta SDL och subsystem
	ge.SDL_SetUp();

	// Sätt bakgrund för spelplan
	ge.setBackground("bg.png");	

	// Lägg till spelarobjekt
	ge.addPlayer("player.png", true);

	// Lägg till fiendeobjekt
	ge.addEnemyTypeOne("enemy.png", true);

	// Lägg till ett andra fiendeobjekt
	ge.addEnemyTypeTwo("enemy2.png", true);

	// Text för startGame()
	ge.setStartScreenTxt("Hello :)");

	// Räknar antalet terminerade fiender
	ge.setFragScoreCounter(true);

	// Skjutriktning, (u=up, d=down, l=left, r=right)
	// Kolliderar med andra objekt 
	// Skjuta av/på
	ge.setPlayerSettings('r', true, true);

	// Hastighet i x-led, 
	// Hastighet i y-led, 
	// Startsida, (t=top, b=bottom, l=left, r=right)
	ge.setEnemyTypeOneSettings(-3, 0, 'r');
	ge.setEnemyTypeTwoSettings(0, 4, 't');

	// Tempo för att lägga till fiender, högra tal -> mer fiender
	ge.setEnemySpawnRate(2);

	// Fiender kan passera genom spelfönstret 
	ge.setEnemysBeyondScreen(true);

	// Text for gameOver()
	ge.setEndScreenTxt("GAME OVER");

	ge.run();


	return 0;
}

