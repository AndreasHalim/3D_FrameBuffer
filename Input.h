#ifndef _INPUT_H_
#define _INPUT_H_

#include <pthread.h>
#include <iostream>
enum class State {RECEIVED = 0, WAITING = 1, STOP = 2};
class Input{
    private:
        const char INTERRUPT_CHARACTER = 'A';
        int isInput = (int)State::WAITING;
        char input;
        pthread_t tid;
    public:
        Input();
        ~Input();
        void *receiveInput();
        void *receiveInputArrowKey();
        void exit();
        char& getInput();
        int& getIsInput();
        void setIsInput(enum State);
};

#endif