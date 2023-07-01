#ifndef __CLEAN_MANAGER_H__
	#define __CLEAN_MANAGER_H__

//********* Include Header files ********
#include "defs.h"
#include "texture.h"

//********** Function Prototypes ***********

void game_clean(App* myApp, GameEntities* gameEntities);
static void clean_entities(GameEntities* gameEntities);

#endif