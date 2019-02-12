#include <iostream>
#include "Render.h"

int main(){
    Render R;
    Color C(255, 255, 255, 255);
    R.drawPoint(Point(100, 200), Color(255, 255, 255, 255));
    Point P1(0, 0);
    Point P2(700, 700);
    Line L(P1, P2);
    R.drawLine(L, C);
    for(;;){
        if(R.getTerminal().getIsInput() == State::RECEIVED){
            R.getTerminal().setIsInput(State::WAITING);
        }
        else if(R.getTerminal().getIsInput() == State::STOP){
            R.getTerminal().exit();
            break;
        }
    }
    return 0;
}