/* Render.cpp */

#include "Render.h"
#include <math.h>

/** Operator Empat Sekawan **/
Render::Render() {
/* Default Constructor */
	
}

Render::Render(Canvas screen) {
/* Parameterized Constructor */

}

Render::Render(const Render &R) {
/* Copy Constructor */	
	
}

/** Getter and Setter **/
Canvas Render::getScreen() const {
	return (this->screen);
}

void Render::setScreen(Canvas screen) {
	this->screen = screen;
}

/** Function and Procedure **/
void Render::draw_line(Line L, Color C) {
	//int r = 255, g = 0, b = 0;
	
	int x_start = L.getP1().getAbsis(); //x0
	int y_start = L.getP1().getOrdinat(); //y0
	int x_end = L.getP2().getAbsis(); //x1
	int y_end = L.getP2().getOrdinat(); //y1
	
	char isHigh = true;
	if(abs(L.getP2().getOrdinat() - L.getP1().getOrdinat()) < abs(L.getP2().getAbsis() - L.getP1().getAbsis())){
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
		/*
		for(int y = y_start; y <= y_end; ++y){
			if(vinfo.bits_per_pixel == 16){
				put_pixel_RGB16(x, y, r, g, b);
			}
			else if(vinfo.bits_per_pixel == 24){
				put_pixel_RGB24(x, y, r, g, b);
			}
			else if(vinfo.bits_per_pixel == 32){
				put_pixel_RGB32(x, y, r, g, b);
			}
			if(D > 0){
				x = x + xi;
				D = D - 2 * dy;
			}
			D += 2 * dx;
		}
		*/
	}
	else{
		int yi = 1;
		if(dy < 0){
			yi = -1;
			dy *= -1;
		}
		int D = 2 * dy - dx, y = y_start;
		/*
		for(int x = x_start; x <= x_end; ++x){
			if(vinfo.bits_per_pixel == 16){
				put_pixel_RGB16(x, y, r, g, b);
			}
			else if(vinfo.bits_per_pixel == 24){
				put_pixel_RGB24(x, y, r, g, b);
			}
			else if(vinfo.bits_per_pixel == 32){
				put_pixel_RGB32(x, y, r, g, b);
			}
			if(D > 0){
				y = y + yi;
				D = D - 2 * dx;
			}
			D += 2 * dy;
		}
		*/
	}
	
}

void Render::draw_shape(Shape S, Color C) {
	
}

void Render::color_shape(Shape S) {
	
}