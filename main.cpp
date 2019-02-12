#include <iostream>
#include "Render.h"

int main(){
    Canvas screen;
    Render R;
    Color C1(0, 0, 0, 200);
    Color Outline1(0, 255, 255, 255);
    Color C2(0, 0, 0, 255);
    Color Outline2(0, 255, 0, 255);
    Point P1(0, 0);
    Point P2(700, 700);
    Line L(P1, P2);
    R.loadAsset("peluru.txt");
    R.loadAsset("ship.txt");
    R.loadAsset("plane.txt");
    R.doMotion();
    // for(;;){
    //     if(R.getTerminal().getIsInput() == (int)State::RECEIVED){
    //         char input = R.getTerminal().getInput();
    //         std::cout << input << std::endl << "\r";
    //         /* switch (input)
    //         {
    //             case 'C':
    //                 R.offset_x++;
    //                 break;
    //             case 'D':
    //                 R.offset_x--;
    //                 break;
    //             default:
    //                 break;
    //         }
	// 		R.clearScreen();
	// 		for(int i = 0; i < R.getAssetCount(); ++i){
	// 			R.drawAsset(i);
	// 		} */
    //         R.getTerminal().setIsInput(State::WAITING);
    //     }
    //     else if(R.getTerminal().getIsInput() == (int)State::STOP){
    //         R.getTerminal().exit();
    //         break;
    //     }
    // }
    return 0;
}