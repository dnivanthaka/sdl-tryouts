#ifndef __VIDEO_H__
#define __VIDEO_H__

#include <string>

#include "SDL2/SDL.h"

class Video 
{
    public:
        int init(
                std::string title, 
                int posx, 
                int posy, 
                int w, 
                int h, 
                int flags
                );
        void draw(
                SDL_Texture* t, 
                SDL_Rect* srect = NULL, 
                SDL_Rect* drect = NULL, 
                double angle = 0, 
                SDL_Point* point = NULL, 
                SDL_RendererFlip flip = SDL_FLIP_NONE
                );
        void render();
        void clear();
        void clean();
        static Video* getInstance(){
            if(s_pInstance == 0){
                s_pInstance = new Video();
            }

            return s_pInstance;
        }

    private:
        Video();
        ~Video();

        static Video* s_pInstance;
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
};

#endif
