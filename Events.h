#ifndef EVENTS_H
#define EVENTS_H

#include "SDL.h"
#include "Sprite.h"
#include "Player.h"
#include <vector>


class Events
{
public:
	Events(SDL_Event*, Player*);
	//~Events();
};



#endif
