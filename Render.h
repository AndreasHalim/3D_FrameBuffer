/* Render.h */

#ifndef _RENDER_H_
#define _RENDER_H_

#include "Canvas.h"
#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Color.h"

class Render {
	private:
		Canvas screen; // Screen size
		
	public:
		/* Operator Empat Sekawan */
		Render();
		Render(Canvas screen);
		Render(const Render &R);
		
		/* Getter and Setter */
		Canvas getScreen() const;
		void setScreen(Canvas screen);
		
		/* Function and Procedure */
		void draw_line(Line L, Color C);
		void draw_shape(Shape S, Color C);
		void color_shape(Shape S);
	
};

#endif