#include "Events.h"


Events::Events(SDL_Event* event, Player * player)
{
	if(event -> type == SDL_KEYDOWN)
	{
		switch(event -> key.keysym.sym)
		{
		case SDLK_UP:		
			player -> keyDown(0); break;	
		case SDLK_DOWN:
			player -> keyDown(1); break;	
		case SDLK_RIGHT:
			player -> keyDown(2); break;
		case SDLK_LEFT:
			player -> keyDown(3); break;	
		case SDLK_SPACE:
			player -> keyDown(4); break;
		}	
	}

	if(event -> type == SDL_KEYUP)
	{
		switch(event -> key.keysym.sym)
		{
		case SDLK_UP:				
			player -> keyUp(0); break;	
		case SDLK_DOWN:				
			player -> keyUp(1); break;	
		case SDLK_RIGHT:				
			player -> keyUp(2); break;
		case SDLK_LEFT:				
			player -> keyUp(3); break;
		case SDLK_SPACE:
			player -> keyUp(4); break;
		}
	}

}