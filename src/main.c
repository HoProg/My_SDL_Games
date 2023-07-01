#include "defs.h"
#include "game_manager.h"
#include "init.h"
#include "clean.h"


int main(int argc, char *argv[])
{
	
	App* myApp = game_init();
	GameEntities* gameEntities = NULL;                                   
	
	if(myApp != NULL)
		while(1)
		{
			game_handle_event(myApp, gameEntities);
			game_update(myApp, &gameEntities);
	        game_render(myApp, gameEntities);
	        SDL_Delay(16);
		}
	
	
	game_clean(myApp, gameEntities);
	return 0;
}