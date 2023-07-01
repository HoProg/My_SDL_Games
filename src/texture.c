#include "texture.h"


//****************************************************
SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, path);
	if(texture == NULL)
		printf("Texture can't be loaded: %s\n", IMG_GetError());

	return texture;
}

//**************************************************

void free_textures(SDL_Texture** gameTextures)
{
	for(int i = 0; i < TOTAL_TEXTURE; i++)
		if(gameTextures[i] != NULL)
		{
			SDL_DestroyTexture(gameTextures[i]);
			gameTextures[i] = NULL;
		}

}