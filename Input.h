#ifndef _INPUT_H_
#define _INPUT_H_

#include <pthread.h>
#include <iostream>
class Input{
    private:
        enum state {RECEIVED, WAITING, STOP};
        enum state isInput = WAITING;
        char input;
        pthread_t tid;
    public:
        Input();
        ~Input();
        void *receiveInput();
        char getInput();
        enum state getIsInput();
};

#endif