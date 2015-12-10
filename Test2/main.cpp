#include <iostream>

#include "SDL2/SDL.h"
#include "Video.h"
#include "Game.h"

std::string winTitle = "Test1";

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;


int main(int argc, char *argv[])
{
    Game::getInstance()->init();
    Video::getInstance()->init(
            winTitle, 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            WINDOW_WIDTH, 
            WINDOW_HEIGHT, 
            SDL_WINDOW_SHOWN);


            //Game *game = Game::getInstance();
            while(Game::getInstance()->running()){
                
                Game::getInstance()->handleEvents();
                Game::getInstance()->update();
                Game::getInstance()->render();
            }

    Video::getInstance()->clean();
    Game::getInstance()->clean();

    return 0;
}
