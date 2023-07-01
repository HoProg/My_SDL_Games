#ifndef __UTILITY_H__
	#define __UTILITY_H__

//***************Include Header files***************
#include "defs.h"

//*****************Preproccessor Macros & consts********************************



//*********Functions prototype***************
SDL_Rect set_option_rect(int x, int y, int w, int h);
void move_player(Entity* player, int direction);
void check_ball_paddles_collision(GameEntities* gameEntities);
void check_ball_wall_collision(Entity* ball);
bool check_ball_out(GameState* gameState, GameEntities* gameEntities);
static void init_ball_and_paddles(GameEntities* gameEntities);



#endif