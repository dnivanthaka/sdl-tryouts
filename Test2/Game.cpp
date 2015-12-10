#include "SDL2/SDL.h"

#include "Video.h"
#include "Game.h"

Game* Game::s_pInstance = 0;

Game::Game()
{
    m_bRunning = true;
}

Game::~Game()
{

}

void Game::init()
{

}

void Game::handleEvents()
{
    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            m_bRunning = false;
        break;
        default:
        break;
        }
    }
}

void Game::update()
{

}

void Game::render()
{
    Video::getInstance()->clear();
    Video::getInstance()->render();
}

void Game::clean()
{
    SDL_Quit();
}

bool Game::running()
{
    return m_bRunning;
}
