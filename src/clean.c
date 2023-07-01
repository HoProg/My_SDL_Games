#include "clean.h"

//***********************************************************

void game_clean(App* myApp, GameEntities* gameEntities)
{
	clean_entities(gameEntities);
	
	if(myApp != NULL)
	{	
		SDL_DestroyRenderer(myApp->renderer);
		SDL_DestroyWindow(myApp->window);
		if(myApp->gameTextures != NULL)
		{	
			free_textures(myApp->gameTextures);
			free(myApp->gameTextures);
		}
		free(myApp);
		myApp = NULL;
	}
	IMG_Quit();
	SDL_Quit();
}

//************************************************************

 static void clean_entities(GameEntities* gameEntities)
 {
 	if(gameEntities != NULL )
 	{
 		if(gameEntities->player01 != NULL)
 			free(gameEntities->player01);
 		if(gameEntities->player02 != NULL)
 			free(gameEntities->player02); 
 		if(gameEntities->ball != NULL)	
 			free(gameEntities->ball);


 		free(gameEntities);
 		gameEntities = NULL;

 	}
 }

