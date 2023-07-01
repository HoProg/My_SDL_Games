#include "init.h"

App* game_init(void)
{
	App* myApp = NULL;

	//******************

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Initialization Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//********************

	if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		printf("SDL_image Initialization Error: %s\n", IMG_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	//**********************

	myApp = malloc(sizeof(App));

	if(myApp != NULL)
	{
		memset(myApp, 0, sizeof(App));

		//************

		if(SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &(myApp->window), &(myApp->renderer)) < 0)
		{
			game_clean(myApp, NULL);			
			exit(EXIT_FAILURE);
		}

		//*************

		myApp->gameTextures = malloc(TOTAL_TEXTURE * sizeof(SDL_Texture*));
		if(myApp->gameTextures != NULL)
		{
			myApp->gameTextures[MENU_BACKGROUND] = load_texture(myApp->renderer, "asset/menuBackground.png");
			myApp->gameTextures[PLAY_BACKGROUND] = load_texture(myApp->renderer, "asset/playBackground.png");
			myApp->gameTextures[PLAY] = load_texture(myApp->renderer, "asset/play.png");
			myApp->gameTextures[OPTION] = load_texture(myApp->renderer, "asset/option.png");
			myApp->gameTextures[EXIT] = load_texture(myApp->renderer, "asset/exit.png");
			myApp->gameTextures[CONFIRM] = load_texture(myApp->renderer, "asset/confirmExit02.png");
			myApp->gameTextures[NO] = load_texture(myApp->renderer, "asset/no.png");
			myApp->gameTextures[YES] = load_texture(myApp->renderer, "asset/yes.png");
			myApp->gameTextures[EXIT_SELECT] = load_texture(myApp->renderer, "asset/exitSelect.png");
			myApp->gameTextures[SELECT] = load_texture(myApp->renderer, "asset/select.png");
			myApp->gameTextures[BALL] = load_texture(myApp->renderer, "asset/ball.png");
			myApp->gameTextures[PADDLE] = load_texture(myApp->renderer, "asset/paddle.png");
			myApp->gameTextures[PRESS_KEY] = load_texture(myApp->renderer, "asset/pressKey.png");

		} 

		//**************
		myApp->gameState = malloc(sizeof(GameState));
		if(myApp->gameState != NULL)
		{
			myApp->gameState->currentState = MAIN_MENU_STATE;
			myApp->gameState->previousState = MAIN_MENU_STATE;
			myApp->gameState->selectOption = M_PLAY;
			
			myApp->gameState->OptionRects = malloc(ALL_OPTIONS * sizeof(SDL_Rect));
			if(myApp->gameState->OptionRects != NULL)
			{
				myApp->gameState->OptionRects[M_PLAY] = set_option_rect(490, 67, 300, 150);
				myApp->gameState->OptionRects[M_OPTION] = set_option_rect(490, 284, 300, 150);
				myApp->gameState->OptionRects[M_EXIT] = set_option_rect(490, 501, 300, 150);

				myApp->gameState->OptionRects[P_RESUME] = set_option_rect(490, 24, 300, 150);
				myApp->gameState->OptionRects[P_RESTART] = set_option_rect(490, 198, 300, 150);
				myApp->gameState->OptionRects[P_OPTION] = set_option_rect(490, 372, 300, 150);
				myApp->gameState->OptionRects[P_EXIT] = set_option_rect(490, 546, 300, 150);

				myApp->gameState->OptionRects[E_CONFIRM] = set_option_rect(340, 135, 600, 300);
				myApp->gameState->OptionRects[E_YES] = set_option_rect(340, 435, 300, 150);
				myApp->gameState->OptionRects[E_NO] = set_option_rect(640, 435, 300, 150);

				myApp->gameState->OptionRects[PRESS_KEY_ON] = set_option_rect(340, 140, 600, 300);
			}

		} 

	}
		
	return myApp;	
}

//****************************************
GameEntities* init_entities(App* myApp)
{
	//srand(time(NULL));
	int theta = rand() % THETA_MAX;

	GameEntities* gameEntities = NULL;
	gameEntities = malloc(sizeof(GameEntities));

	if(gameEntities != NULL)
	{
		memset(gameEntities, 0, sizeof(GameEntities));
		gameEntities->player01 = malloc(sizeof(Entity));
		gameEntities->player02 = malloc(sizeof(Entity));
		gameEntities->ball = malloc(sizeof(Entity));

		if(gameEntities->player01 != NULL && gameEntities->player02 != NULL && gameEntities->ball != NULL)
		{
			SDL_QueryTexture(myApp->gameTextures[PADDLE], NULL, NULL, &(gameEntities->player01->rect.w), &(gameEntities->player01->rect.h));
			SDL_QueryTexture(myApp->gameTextures[BALL], NULL, NULL, &(gameEntities->ball->rect.w), &(gameEntities->ball->rect.h));

			gameEntities->player01->rect.x = SCREEN_WIDTH - 40;
			gameEntities->player01->rect.y = SCREEN_HEIGHT - 60;
			gameEntities->player01->velocity.x = 0;
			gameEntities->player01->velocity.y = PADDLE_SPEED;


			gameEntities->player02->rect.x = 20;
			gameEntities->player02->rect.y = 20;
			gameEntities->player02->rect.w = gameEntities->player01->rect.w;
			gameEntities->player02->rect.h = gameEntities->player01->rect.h;
			gameEntities->player02->velocity.x = 0;
			gameEntities->player02->velocity.y = PADDLE_SPEED;

			gameEntities->ball->rect.x = (SCREEN_WIDTH - gameEntities->ball->rect.w) / 2;
			gameEntities->ball->rect.y = (SCREEN_HEIGHT - gameEntities->ball->rect.h) / 2;


			gameEntities->ball->velocity.x = (int)(BALL_SPEED * cos(theta * PI / THETA_MAX));
			if(gameEntities->ball->velocity.x == 0)
				gameEntities->ball->velocity.x = BALL_SPEED;
			gameEntities->ball->velocity.y = (int)(BALL_SPEED * sin(theta * PI / THETA_MAX));

		}
		else
			printf("Dynamic allocation problem...\n");
	}
	else
			printf("Dynamic allocation problem...\n");


	return gameEntities;
}

