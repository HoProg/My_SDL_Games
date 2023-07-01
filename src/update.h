#ifndef __UPDATE_H__
	#define __UPADATE_H__

#include "defs.h"
#include "init.h"
#include "utility.h"


void main_menu_update(App* myApp);
void pressKey_update(App* myApp, GameEntities** gameEntities);
void play_update(GameState* gameState, GameEntities* gameEntities);
void option_update(App* myApp);
void exit_update(App* myApp);




#endif