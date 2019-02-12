#ifndef _INPUT_H_
#define _INPUT_H_

#include <pthread.h>
#include <iostream>
enum class State {RECEIVED, WAITING, STOP};
class Input{
    private:
        const char INTERRUPT_CHARACTER = 'A';
        State isInput = State::WAITING;
        char input;
        pthread_t tid;
    public:
        Input();
        ~Input();
        void *receiveInput();
        void *receiveInputArrowKey();
        void exit();
        char getInput();
        enum State getIsInput();
        void setIsInput(enum State);
};

#endif