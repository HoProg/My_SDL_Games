#include "update.h"


void main_menu_update(App* myApp)
{
	/*switch(myApp->gameState->selectOption)
    {
    	case M_PLAY:printf("Playing...\n");break;
    	case M_OPTION:printf("Choose option...");break;
    	case M_EXIT:printf("Quit game...");break;
    	default: break;
    }*/
}

//*********************************
void pressKey_update(App* myApp, GameEntities** gameEntities)
{
    static int refTicks = 0;

    if(*gameEntities == NULL)
    {
        *gameEntities = init_entities(myApp);
        return;
    }

    if ((SDL_GetTicks() - refTicks) > SECOND)
    {
        if(myApp->gameState->selectOption == PRESS_KEY_OFF)
            myApp->gameState->selectOption = PRESS_KEY_ON;
        else
           myApp->gameState->selectOption = PRESS_KEY_OFF; 

        refTicks = SDL_GetTicks();
    }
    

}



//*********************************
void play_update(GameState* gameState, GameEntities* gameEntities)
{
    if(!check_ball_out(gameState, gameEntities))
    {
        check_ball_wall_collision(gameEntities->ball);
        check_ball_paddles_collision(gameEntities);

        gameEntities->ball->rect.x += gameEntities->ball->velocity.x;
        gameEntities->ball->rect.y += gameEntities->ball->velocity.y;
    }
}

//**************************************
void option_update(App* myApp)
{

}

//**************************************
void exit_update(App* myApp)
{
    /*switch(myApp->gameState->selectOption)
    {
        case E_NO:printf("Return...\n");break;
        case E_YES:printf("Exit the game...");break;
        default: break;
    }*/
}

