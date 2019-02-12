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
		Canvas screen; // Screen size
		Input terminal;
	public:
		/* Operator Empat Sekawan */
		Render();
		Render(const Render &R);
		
		/* Getter and Setter */
		Canvas getScreen() const;
		
		/* Function and Procedure */
		void drawPoint(Point P, Color C);
		void drawLine(Line L, Color C);
		void drawFullShape(Shape S, Color C);
		void drawEmptyShape(Shape S, Color C);
		void clearScreen();	
		Input getTerminal();
};

#endif