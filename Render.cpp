/* Render.cpp */

#include "Render.h"
#include <math.h>

/** Operator Empat Sekawan **/
Render::Render() {
/* Default Constructor */
}

Render::Render(const Render &R) {
/* Copy Constructor */	
	
}

/** Getter and Setter **/
Canvas Render::getScreen() const {
	return (this->screen);
}

void Render::drawPoint(Point P, Color C){
	if(screen.getColorDepth() == 16){
		// x * 2 as every pixel is 2 consecutive bytes
		unsigned int pix_offset = P.getAbsis() * 2 + P.getOrdinat() * screen.getLineLength();
		//unsigned short c = ((r / 8) << 11) + ((g / 4) << 5) + (b / 8);
		unsigned short color = ((C.getRed() / 8) * 2048) + ((C.getGreen() / 4) * 32) + (C.getBlue() / 8);
		// write 2 bytes at once
		*((unsigned short*)(screen.getFrameBuffer() + pix_offset)) = color;
	}
	else if(screen.getColorDepth() == 24){
		// x * 3 as every pixel is 3 consecutive bytes
		unsigned int pix_offset = P.getAbsis() * 3 + P.getOrdinat() * screen.getLineLength();
		// now this is about the same as 'fbp[pix_offset] = value'
		*((char*)(screen.getFrameBuffer() + pix_offset)) = C.getBlue();
		*((char*)(screen.getFrameBuffer() + pix_offset + 1)) = C.getGreen();
		*((char*)(screen.getFrameBuffer() + pix_offset + 2)) = C.getRed();
	}
	else if(screen.getColorDepth() == 32){
		 // x * 2 as every pixel is 2 consecutive bytes
		unsigned int pix_offset = P.getAbsis() * 4 + P.getOrdinat() * screen.getLineLength();
		unsigned int color = (C.getAlpha() << 24) + (C.getRed() << 16) + (C.getGreen() << 8) + C.getBlue();
		// write 4 bytes at once
		*((unsigned int*)(screen.getFrameBuffer() + pix_offset)) = color;
	}
}

/** Function and Procedure **/
void Render::drawLine(Line L, Color C) {
	//int r = 255, g = 0, b = 0;
	int z = 0;
	int x_start = L.getP1().getAbsis(); //x0
	int y_start = L.getP1().getOrdinat(); //y0
	int x_end = L.getP2().getAbsis(); //x1
	int y_end = L.getP2().getOrdinat(); //y1
	
	bool isHigh = true;
	if(abs(int(L.getP2().getOrdinat() - L.getP1().getOrdinat())) < abs(int(L.getP2().getAbsis() - L.getP1().getAbsis()))){
		isHigh = false;
	}
	if(L.getP1().getAbsis() > L.getP2().getAbsis() || L.getP1().getOrdinat() > L.getP2().getOrdinat()){
		x_start = L.getP2().getAbsis();
		y_start = L.getP2().getOrdinat();
		x_end = L.getP1().getAbsis();
		y_end = L.getP1().getOrdinat();
	}
	int dx = x_end - x_start, dy = y_end - y_start;
	if(isHigh){
		int xi = 1;
		if(dx < 0){
			xi = -1;
			dx *= -1;
		}
		int D = 2 * dx - dy, x = x_start;
		for(int y = y_start; y <= y_end; ++y){
			drawPoint(Point(x, y, z), C);
			if(D > 0){
				x = x + xi;
				D = D - 2 * dy;
			}
			D += 2 * dx;
		}
	}
	else{
		int yi = 1;
		if(dy < 0){
			yi = -1;
			dy *= -1;
		}
		int D = 2 * dy - dx, y = y_start;
		for(int x = x_start; x <= x_end; ++x){
			drawPoint(Point(x, y, z), C);
			if(D > 0){
				y = y + yi;
				D = D - 2 * dx;
			}
			D += 2 * dy;
		}
	}
	
}

void Render::drawFullShape(Shape S, Color C) {
	if(!S.isClosed()){
		return;
	}
	for(int i = 0; i < S.getNeff(); ++i){
		drawLine(S.getLineAt(i), C);
	}
	// Color inside shape TBD
}

void Render::drawEmptyShape(Shape S, Color C){
	for(int i = 0; i < S.getNeff(); ++i){
		drawLine(S.getLineAt(i), C);
	}
}

void Render::clearScreen(){
	memset(screen.getFrameBuffer(), 0, (screen.getColorDepth() / 8 * screen.getXRes() * screen.getYRes()));
}