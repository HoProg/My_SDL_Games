#ifndef __GAME_MANAGER_H__
	#define __GAME_MANAGER_H__


//********* Include Header files ******** 
#include "defs.h"
#include "handle_event.h"
#include "update.h"
#include "render.h"
#include "utility.h"

//******** Function Prototypes ***********

void game_handle_event(App* myApp, GameEntities* gameEntities);
void game_update(App* myApp, GameEntities** gameEntities);
void game_render(App* myApp, GameEntities* gameEntities);


#endif