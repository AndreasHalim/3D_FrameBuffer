#include "Input.h"

Input::Input(){
    typedef void * (*THREADFUNCPTR)(void *);
    //system("setterm -cursor off && /bin/stty raw -echo && clear");
    pthread_create(&tid, NULL, (THREADFUNCPTR)&Input::receiveInputArrowKey, this);
}

Input::~Input(){
}

void * Input::receiveInput(){
    while(isInput != (int)State::STOP){
		while(isInput == (int)State::RECEIVED);
		if(input = getchar()){
			std::cout << input << std::endl;
			if(input == INTERRUPT_CHARACTER){
				isInput = (int)State::STOP;
			}
			else{
				isInput = (int)State::RECEIVED;
			}
		}
	}
	return 0;
}

void * Input::receiveInputArrowKey(){
    while(isInput != (int)State::STOP){
		while(isInput == (int)State::RECEIVED);
		if(input = getchar()){
			if(input == 27){
				getchar();
				input = getchar();
			}
			if(input == INTERRUPT_CHARACTER){
				isInput = (int)State::STOP;
			}
			else{
				isInput = (int)State::RECEIVED;
			}
		}
	}
	return 0;
}

void Input::exit(){
	//system("/bin/stty -raw echo && clear");
	pthread_exit(NULL);
}

char& Input::getInput(){
    return input;
}

int& Input::getIsInput(){
    return isInput;
}

void Input::setIsInput(State s){
	isInput = (int)s;
}