#include "handle_event.h"


void main_menu_handle_event(GameState* gameState)
{
	SDL_Event event;

	if(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			gameState->currentState = EXIT_STATE;
			gameState->selectOption = E_NO;
		}

    	else if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
    	{
        	switch(event.key.keysym.sym)
        	{

	            case SDLK_UP: {
	            	if(gameState->selectOption != M_PLAY)
	            		(gameState->selectOption)--;
	            }break;

	            case SDLK_DOWN: {
	            	if(gameState->selectOption != M_EXIT)
	            		(gameState->selectOption)++;	
	            }break;

	            case SDLK_RETURN: 
	            {
	            	if(gameState->selectOption == M_PLAY)
	            	{
	            		gameState->previousState = PRESS_KEY_TO_PLAY_STATE;
	            		gameState->currentState = PRESS_KEY_TO_PLAY_STATE;
	            		gameState->selectOption = PRESS_KEY_ON;
	            	}

	            	else if(gameState->selectOption == M_OPTION)
	            	{
	            		gameState->currentState = OPTION_STATE;
	            	}

	            	else if(gameState->selectOption == M_EXIT)
	            	{
	            		gameState->currentState = EXIT_STATE;
	            		gameState->selectOption = E_NO;
	            	}
	            }break;

	            default: break;
	        }	

        }
    }
}

//**************************************************************
void pressKey_handle_event(GameState* gameState)
{
	SDL_Event event;
	if(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			gameState->currentState = EXIT_STATE;
			gameState->selectOption = E_NO;
		}

		if(event.type == SDL_KEYDOWN) 
		{
		  	gameState->previousState = PLAY_STATE;
		    gameState->currentState = PLAY_STATE;
		    gameState->selectOption = P_RESUME;
		}
	}

}

//***************************************
void play_handle_event(GameState* gameState, GameEntities* gameEntities)
{
	SDL_Event event;
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gameState->currentState = EXIT_STATE;
            gameState->selectOption = E_NO;
        }
    }

    // Update player 01 movement
    if (keystate[SDL_SCANCODE_UP])
        move_player(gameEntities->player01, UP);
     
    if (keystate[SDL_SCANCODE_DOWN]) 
        move_player(gameEntities->player01, DOWN);
    

    // Update player 02 movement
    if (keystate[SDL_SCANCODE_Q]) 
        move_player(gameEntities->player02, UP);

    if (keystate[SDL_SCANCODE_S]) 
        move_player(gameEntities->player02, DOWN);
    
}

//******************************************
void option_handle_event(GameState* gameState)
{

}

//**************************************
void exit_handle_event(App* myApp, GameEntities* gameEntities)
{
	SDL_Event event;

	if(SDL_PollEvent(&event) != 0)
	{
    	if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
    	{
        	switch(event.key.keysym.sym)
        	{
	            case SDLK_RIGHT: {
	            	if(myApp->gameState->selectOption == E_NO)
	            		myApp->gameState->selectOption = E_YES;
	            	else
	            		myApp->gameState->selectOption = E_NO;
	            }break;

	        case SDLK_LEFT: {
	            	if(myApp->gameState->selectOption == E_NO)
	            		myApp->gameState->selectOption = E_YES;
	            	else
	            		myApp->gameState->selectOption = E_NO;
	            }break;


	            case SDLK_RETURN: 
	            {
	            	if(myApp->gameState->selectOption == E_NO)
	            	{
	            		myApp->gameState->currentState = myApp->gameState->previousState;
	            		myApp->gameState->selectOption = M_EXIT;
	            	}

	            	else if(myApp->gameState->selectOption == E_YES)
	            	{
	            		game_clean(myApp, gameEntities);
	            		exit(0);
	            	}

	            }break;

	            default: break;
	        }	

        }
    }
}

