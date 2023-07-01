#include "game_manager.h"



//***********************************************************
void game_handle_event(App* myApp, GameEntities* gameEntities)
{
	switch(myApp->gameState->currentState)
	{
		case MAIN_MENU_STATE: main_menu_handle_event(myApp->gameState);break;
		case PRESS_KEY_TO_PLAY_STATE: pressKey_handle_event(myApp->gameState);break;
		case PLAY_STATE: play_handle_event(myApp->gameState, gameEntities);break;
		case OPTION_STATE: option_handle_event(myApp->gameState);break;
		case EXIT_STATE: exit_handle_event(myApp, gameEntities);break;
		default: break;
	}
}

//**********************************************************
void game_update(App* myApp, GameEntities** gameEntities)
{
	switch(myApp->gameState->currentState)
	{
		case MAIN_MENU_STATE: main_menu_update(myApp);break;
		case PRESS_KEY_TO_PLAY_STATE: pressKey_update(myApp, gameEntities);break;	
		case PLAY_STATE: play_update(myApp->gameState, *gameEntities);break;
		case OPTION_STATE: option_update(myApp);break;
		case EXIT_STATE: exit_update(myApp);break;
		default: break;
	}

}

//**********************************************************
void game_render(App* myApp, GameEntities* gameEntities)
{
	SDL_SetRenderDrawColor(myApp->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(myApp->renderer);

	switch(myApp->gameState->currentState)
	{
		case MAIN_MENU_STATE: main_menu_render(myApp);break;
		case PRESS_KEY_TO_PLAY_STATE: pressKey_render(myApp, gameEntities);break;
		case PLAY_STATE: play_render(myApp, gameEntities);break;
		case OPTION_STATE: option_render(myApp);break;
		case EXIT_STATE: exit_render(myApp);break;
		default: break;
	}

	SDL_RenderPresent(myApp->renderer);	
}

