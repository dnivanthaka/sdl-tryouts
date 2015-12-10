#include <iostream>
#include "SDL2/SDL.h"

#include "Video.h"

Video* Video::s_pInstance = 0;

Video::Video()
{
    m_pWindow   = NULL;
    m_pRenderer = NULL;
}

Video::~Video()
{

}

int Video::init(std::string title, int posx, int posy, int w, int h, int flags)
{
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        if((m_pWindow = SDL_CreateWindow(
                        title.c_str(), 
                        posx, 
                        posy, 
                        w, 
                        h, 
                        flags)) != NULL ){

            if( (m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL){
                std::cout << "SDL Error: Cannot create renderer" << std::endl;
                SDL_DestroyWindow(m_pWindow);
                return 1;
            }


            //Game *game = Game::getInstance();
        }else{
            std::cout << "SDL Error: Cannot create window." << std::endl;
            SDL_DestroyWindow(m_pWindow);
            return 1;
        } 
    }else{
        std::cout << "SDL Error: Error initializing SDL." << std::endl;
        return 1;
    }

    return 0;

}

void Video::render()
{
    SDL_RenderPresent(m_pRenderer);
}

void Video::draw(
           SDL_Texture* t, 
           SDL_Rect* srect, 
           SDL_Rect* drect, 
           double angle, 
           SDL_Point* point, 
           SDL_RendererFlip flip
         )
{
    SDL_RenderCopyEx(m_pRenderer, t, srect, drect, angle, point, flip);
}

void Video::clear()
{
    SDL_RenderClear(m_pRenderer);
}

void Video::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
}
