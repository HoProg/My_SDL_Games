#ifndef __TEXTURE_H__
	#define __TEXTURE_H__

//********* Include Header files ********
#include "defs.h"

//********** Function Prototypes ***********

SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path);
void free_textures(SDL_Texture** gameTextures);


#endif