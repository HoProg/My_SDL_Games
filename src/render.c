#include "render.h"

void main_menu_render(App* myApp)
{
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[MENU_BACKGROUND], NULL, NULL);
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PLAY], NULL, &(myApp->gameState->OptionRects[M_PLAY]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[OPTION], NULL, &(myApp->gameState->OptionRects[M_OPTION]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[EXIT], NULL, &(myApp->gameState->OptionRects[M_EXIT]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[SELECT], NULL, &(myApp->gameState->OptionRects[myApp->gameState->selectOption]));
}

//*******************************
void pressKey_render(App* myApp, GameEntities* gameEntities)
{
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PLAY_BACKGROUND], NULL, NULL);
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PADDLE], NULL, &(gameEntities->player01->rect));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PADDLE], NULL, &(gameEntities->player02->rect));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[BALL], NULL, &(gameEntities->ball->rect));

	if(myApp->gameState->selectOption == PRESS_KEY_ON)
		SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PRESS_KEY], NULL, &(myApp->gameState->OptionRects[PRESS_KEY_ON]));
}

//*******************************
void play_render(App* myApp, GameEntities* gameEntities)
{
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PLAY_BACKGROUND], NULL, NULL);
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PADDLE], NULL, &(gameEntities->player01->rect));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[PADDLE], NULL, &(gameEntities->player02->rect));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[BALL], NULL, &(gameEntities->ball->rect));
}

//***********************************
void option_render(App* myApp)
{

}

//**********************************
void exit_render(App* myApp)
{
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[MENU_BACKGROUND], NULL, NULL);
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[CONFIRM], NULL, &(myApp->gameState->OptionRects[E_CONFIRM]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[NO], NULL, &(myApp->gameState->OptionRects[E_NO]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[YES], NULL, &(myApp->gameState->OptionRects[E_YES]));
	SDL_RenderCopy(myApp->renderer, myApp->gameTextures[EXIT_SELECT], NULL, &(myApp->gameState->OptionRects[myApp->gameState->selectOption]));
}

