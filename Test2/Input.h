#ifndef __INPUT_H__
#define __INPUT_H__
class Input
{
    public:
        int init();
        static Input* getInstance()
        {
            if(s_pInput == 0){
                s_pInput = new Input();
            }

            return s_pInput;
        }

    private:
        Input();
        ~Input();

        static Input* s_pInput;
};
#endif
