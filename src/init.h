#ifndef __INIT_MANAGER_H__
	#define __INIT_MANAGER_H__


//********* Include Header files ********
#include "defs.h"
#include "clean.h"
#include "texture.h"
#include "utility.h"


//********** Function Prototypes ***********

App* game_init(void);
GameEntities* init_entities(App* myApp);

#endif
