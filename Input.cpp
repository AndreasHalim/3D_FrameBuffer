#include "Input.h"

Input::Input(){
    typedef void * (*THREADFUNCPTR)(void *);
    system("setterm -cursor off && /bin/stty raw -echo && clear");
    pthread_create(&tid, NULL, (THREADFUNCPTR)&Input::receiveInput, this);
}

Input::~Input(){
    system("/bin/stty -raw echo && clear");
	pthread_exit(NULL);
}

void * Input::receiveInput(){
    while(isInput != STOP){
		while(isInput == RECEIVED);
		if(input = getchar()){
			if(input == 27){
				getchar();
				input = getchar();
			}
			if(input == 'A'){
				printf("\n\r");
				isInput = STOP;
			}
			else{
				isInput = RECEIVED;
			}
		}
	}
	return 0;
}