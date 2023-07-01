#ifndef __HANDLE_EVENT_H__
	#define __HANDLE_EVENT_H__

#include "defs.h"
#include "utility.h"

void main_menu_handle_event(GameState* gameState);
void pressKey_handle_event(GameState* gameState);
void play_handle_event(GameState* gameState, GameEntities* gameEntities);
void option_handle_event(GameState* gameState);
void exit_handle_event(App* myApp, GameEntities* gameEntities);




#endif