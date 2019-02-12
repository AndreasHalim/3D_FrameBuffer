/* Render.h */

#ifndef _RENDER_H_
#define _RENDER_H_

#include "Canvas.h"
#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Color.h"
#include "Input.h"

class Render {
	private:
		const Color BACKGROUND = Color(0, 0, 0, 0);
		Canvas screen; // Screen size
		Input terminal;
		Shape shapes[100];
		Color fills[100];
		Color outlines[100];
		int asset_count = 0;
		void drawLineLow(int x0, int y0, int x1, int y1, Color C);
		void drawLineHigh(int x0, int y0, int x1, int y1, Color C);
	public:
		int offset_x = screen.getXRes() / 3, offset_y = screen.getYRes() / 2; 
		/* Operator Empat Sekawan */
		Render();
		Render(const Render &R);
		~Render();
		/* Getter and Setter */
		Canvas getScreen() const;
		int getAssetCount();
		/* Function and Procedure */
		void drawPoint(Point P, Color C);
		void drawLine(Line L, Color C);
		void loadAsset(char *filename);
		void drawAsset(int idx);
		void doMotion();
		void drawFullShape(Shape S, Color C, Color Outline);
		void drawEmptyShape(Shape S, Color Outline);
		void clearScreen();	
		Input getTerminal();
		Color getBGColor();
};

#endif