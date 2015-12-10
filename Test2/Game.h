#ifndef __GAME_H__
#define __GAME_H__
class Game
{
    public:
        void init();
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running();
        static Game* getInstance(){
            if(s_pInstance == 0){
                s_pInstance = new Game();
            }

            return s_pInstance;
        }

    private:
        Game();
        ~Game();

        static Game* s_pInstance;
        bool m_bRunning;
};

//typedef Game TheGame;
#endif
