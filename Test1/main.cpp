#include <iostream>

#include "SDL2/SDL.h"

std::string winTitle = "Test1";

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

SDL_Window* g_pWindow     = NULL;
SDL_Renderer* g_pRenderer = NULL;

bool gameIsRunning = true;

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        if((g_pWindow = SDL_CreateWindow(
                        winTitle.c_str(), 
                        SDL_WINDOWPOS_CENTERED, 
                        SDL_WINDOWPOS_CENTERED, 
                        WINDOW_WIDTH, 
                        WINDOW_HEIGHT, 
                        SDL_WINDOW_SHOWN)) != NULL ){

            if( (g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0)) == NULL){
                std::cout << "SDL Error: Cannot create renderer" << std::endl;
                SDL_DestroyWindow(g_pWindow);
                return 1;
            }
        // Game activity
        while( gameIsRunning ){
            SDL_Event event;

            if(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_QUIT:
                        gameIsRunning = false;
                    break;
                    default:
                    break;
                }
            }


            SDL_RenderClear(g_pRenderer);
            SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
            SDL_RenderPresent(g_pRenderer);
        }
        }else{
            std::cout << "SDL Error: Cannot create window." << std::endl;
            SDL_DestroyWindow(g_pWindow);
            return 1;
        } 
    }else{
        std::cout << "SDL Error: Error Initializing SDL." << std::endl;
        return 1;
    }

    SDL_DestroyWindow(g_pWindow);
    SDL_DestroyRenderer(g_pRenderer);
    SDL_Quit();

    return 0;
}
