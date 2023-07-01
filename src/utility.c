#include "utility.h"

SDL_Rect set_option_rect(int x, int y, int w, int h)
{
	SDL_Rect rect = {x, y, w, h};

	return rect;
}

//*********************************************************
void move_player(Entity* player, int direction)
{
	if (direction == UP)
	{
		player->rect.y -= player->velocity.y;
		if(player->rect.y < 0)
			player->rect.y = 0;
	}
	else if (direction == DOWN)
	{
		player->rect.y += player->velocity.y;
		if ((player->rect.y + player->rect.h) > SCREEN_HEIGHT)
			player->rect.y = SCREEN_HEIGHT - player->rect.h;
	}
		
}

//**********************************************************
void check_ball_paddles_collision(GameEntities* gameEntities)
{
	if(gameEntities->ball->velocity.x < 0)
	{
		if( gameEntities->ball->rect.x <= (gameEntities->player02->rect.x + gameEntities->player02->rect.w) &&
			gameEntities->ball->rect.x >= gameEntities->player02->rect.x &&
			gameEntities->ball->rect.y <= (gameEntities->player02->rect.y + gameEntities->player02->rect.h) &&
			(gameEntities->ball->rect.y + gameEntities->ball->rect.h) >= gameEntities->player02->rect.y)
		{
			gameEntities->ball->velocity.x *= -1;
			gameEntities->ball->velocity.x++;
		}

	}

	else
	{
		if((gameEntities->ball->rect.x + gameEntities->ball->rect.w) <= (gameEntities->player01->rect.x + gameEntities->player01->rect.w) &&
			(gameEntities->ball->rect.x + gameEntities->ball->rect.w) >= gameEntities->player01->rect.x &&
			gameEntities->ball->rect.y <= (gameEntities->player01->rect.y + gameEntities->player01->rect.h) &&
			(gameEntities->ball->rect.y + gameEntities->ball->rect.h) >= gameEntities->player01->rect.y)
		{
			gameEntities->ball->velocity.x *= -1;
			gameEntities->ball->velocity.x--;
		}
	}
}

//********************************************************

void check_ball_wall_collision(Entity* ball)
{
	if(ball->rect.y <= 0 || (ball->rect.y + ball->rect.h) > SCREEN_HEIGHT)
	{
		ball->velocity.y *= -1;
	}
}

//****************************************************
bool check_ball_out(GameState* gameState, GameEntities* gameEntities)
{
	if(gameEntities->ball->rect.x > SCREEN_WIDTH || (gameEntities->ball->rect.x + gameEntities->ball->rect.w) <= 0)
	{
		init_ball_and_paddles(gameEntities);
		gameState->previousState = PRESS_KEY_TO_PLAY_STATE;
	    gameState->currentState = PRESS_KEY_TO_PLAY_STATE;
	    gameState->selectOption = PRESS_KEY_ON;

	    return true;
	}

	return false;
}

//*******************************
static void init_ball_and_paddles(GameEntities* gameEntities)
{
	//srand(time(NULL));
	int theta = rand() % THETA_MAX;

	gameEntities->player01->rect.x = SCREEN_WIDTH - 40;
	gameEntities->player01->rect.y = SCREEN_HEIGHT - 60;

	gameEntities->player02->rect.x = 20;
	gameEntities->player02->rect.y = 20;

 	gameEntities->ball->rect.x = (SCREEN_WIDTH - gameEntities->ball->rect.w) / 2;
	gameEntities->ball->rect.y = (SCREEN_HEIGHT - gameEntities->ball->rect.h) / 2;

    gameEntities->ball->velocity.x = (int)(BALL_SPEED * cos(theta * PI / THETA_MAX));
    if(gameEntities->ball->velocity.x >= 0 && gameEntities->ball->velocity.x < (BALL_SPEED / 3))
		gameEntities->ball->velocity.x = BALL_SPEED / 2;
	else if(gameEntities->ball->velocity.x < 0 && gameEntities->ball->velocity.x > (-BALL_SPEED / 3))
		gameEntities->ball->velocity.x = -BALL_SPEED / 2;

	gameEntities->ball->velocity.y = (int)(BALL_SPEED * sin(theta * PI / THETA_MAX));
	if(gameEntities->ball->velocity.y == 0)
		gameEntities->ball->velocity.y = BALL_SPEED / 2;
}





