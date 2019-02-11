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
    while(1);
    return 0;
}