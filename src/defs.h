#ifndef __DEFS_H__
	#define __DEFS_H__

//********* Include Header files ********

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math.h"
#include "time.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//******** Preprocessor & macros *********

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define THETA_MAX 360
#define PI 3.14159265

#define PADDLE_SPEED 10
#define BALL_SPEED 10

#define SECOND 600


//********* Define Types ********


typedef enum State {MAIN_MENU_STATE, PRESS_KEY_TO_PLAY_STATE, PLAY_STATE, OPTION_STATE, EXIT_STATE, GAME_STATES}State;

enum GameTexture {PLAY, OPTION, EXIT, RESTART, RESUME, BACK, SELECT, CONFIRM, NO, YES, EXIT_SELECT, PRESS_KEY, MENU_BACKGROUND, PLAY_BACKGROUND, BALL, PADDLE, TOTAL_TEXTURE};

enum Direction {NONE, UP, DOWN, RIGHT, LEFT};

typedef enum StateOptions {PRESS_KEY_ON, PRESS_KEY_OFF,
						   M_PLAY, M_OPTION, M_EXIT, 
				   		   P_RESUME, P_RESTART, P_OPTION, P_EXIT, 
				           O_GAME_SPEED, O_BALLS, O_BACK, 
				           E_NO, E_YES, E_CONFIRM, 
				           ALL_OPTIONS}StateOptions;


typedef struct Entity
{
	SDL_Rect rect;
	SDL_Point velocity;			
}Entity;

typedef struct GameEntities
{
	Entity* player01; 
	Entity* player02;
	Entity* ball;
}GameEntities;

typedef struct GameState
{
	State currentState;
	State previousState;
	StateOptions selectOption;
	SDL_Rect* OptionRects;

}GameState;


typedef struct
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture** gameTextures;
	GameState* gameState;
}App;




#endif