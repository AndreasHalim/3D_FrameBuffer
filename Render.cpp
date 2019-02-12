/* Render.cpp */

#include "Render.h"
#include <math.h>

/** Operator Empat Sekawan **/
Render::Render():screen(), terminal() {
/* Default Constructor */
}

Render::Render(const Render &R) {
/* Copy Constructor */	
	
}

Render::~Render() {

}

/** Getter and Setter **/
Canvas Render::getScreen() const {
	return (this->screen);
}

int Render::getAssetCount() {
	return (this->asset_count);
}

void Render::drawPoint(Point P, Color C){
	if(P.getAbsis() + offset_x >= screen.getXRes() || P.getAbsis() - offset_x < 0 || P.getOrdinat() + offset_y >= screen.getYRes() || P.getOrdinat() - offset_y < 0)
		return;
	if(screen.getColorDepth() == 16){
		// x * 2 as every pixel is 2 consecutive bytes
		unsigned int pix_offset = (P.getAbsis() + offset_x) * 2 + (P.getOrdinat() + offset_y) * screen.getLineLength();
		//unsigned short c = ((r / 8) << 11) + ((g / 4) << 5) + (b / 8);
		unsigned short color = ((C.getRed() / 8) * 2048) + ((C.getGreen() / 4) * 32) + (C.getBlue() / 8);
		// write 2 bytes at once
		if(*((unsigned short*)(screen.getFrameBuffer() + pix_offset)) != color){
			*((unsigned short*)(screen.getFrameBuffer() + pix_offset)) = color;
		}
	}
	else if(screen.getColorDepth() == 24){
		// x * 3 as every pixel is 3 consecutive bytes
		unsigned int pix_offset = (P.getAbsis() + offset_x) * 3 + (P.getOrdinat() + offset_y) * screen.getLineLength();
		// now this is about the same as 'fbp[pix_offset] = value'
		if(*((char*)(screen.getFrameBuffer() + pix_offset)) != C.getBlue() || *((char*)(screen.getFrameBuffer() + pix_offset + 1)) != C.getGreen() && *((char*)(screen.getFrameBuffer() + pix_offset + 2)) != C.getRed()){
			*((char*)(screen.getFrameBuffer() + pix_offset)) = C.getBlue();
			*((char*)(screen.getFrameBuffer() + pix_offset + 1)) = C.getGreen();
			*((char*)(screen.getFrameBuffer() + pix_offset + 2)) = C.getRed();
		}
	}
	else if(screen.getColorDepth() == 32){
		 // x * 2 as every pixel is 2 consecutive bytes
		unsigned int pix_offset = (P.getAbsis() + offset_x) * 4 + (P.getOrdinat() + offset_y) * screen.getLineLength();
		unsigned int color = (C.getAlpha() << 24) + (C.getRed() << 16) + (C.getGreen() << 8) + C.getBlue();
		// write 4 bytes at once
		if(*((unsigned int*)(screen.getFrameBuffer() + pix_offset)) != color){
			*((unsigned int*)(screen.getFrameBuffer() + pix_offset)) = color;
		}
	}
}

/** Function and Procedure **/
void Render::drawLineLow(int x0, int y0, int x1, int y1, Color C){
	int dx = x1 - x0;
	int dy = y1 - y0;
  	int yi = 1;
  	if(dy < 0){
		yi = -1;
		dy = -1 * dy;
	}
  	int D = 2 * dy - dx;
  	int y = y0;
	for(int x = x0; x <= x1; ++x){
		drawPoint(Point(x, y), C);
		if(D > 0){
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void Render::drawLineHigh(int x0, int y0, int x1, int y1, Color C){
	int dx = x1 - x0;
	int dy = y1 - y0;
  	int xi = 1;
  	if(dx < 0){
		xi = -1;
		dx = -1 * dx;
	}
  	int D = 2 * dx - dy;
  	int x = x0;
	for(int y = y0; y <= y1; ++y){
		drawPoint(Point(x, y), C);
		if(D > 0){
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
	}
}

void Render::drawLine(Line L, Color C) {
	int x0 = L.getP1().getAbsis();
	int x1 = L.getP2().getAbsis();
	int y0 = L.getP1().getOrdinat();
	int y1 = L.getP2().getOrdinat();
	if(abs(y1 - y0) < abs(x1 - x0)){
		if(x0 > x1){
			drawLineLow(x1, y1, x0, y0, C);
		}
		else{
			drawLineLow(x0, y0, x1, y1, C);
		}
	}
	else{
		if(y0 > y1){
			drawLineHigh(x1, y1, x0, y0, C);
		}
		else{
			drawLineHigh(x0, y0, x1, y1, C);
		}
	}
}

void Render::loadAsset(char *filename){
	int shape_count, line_count;
	char asset_type;
	FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error opening the file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &shape_count);
	//std::cout << shape_count << std::endl << "\r";
	for(int i = 0; i < shape_count; ++i){
		int r, g, b, a;
		fscanf(fp, "\n%c", &asset_type);
		fscanf(fp, "%d", &line_count);
		//std::cout << asset_type << ", " << line_count << std::endl << "\r";
		fscanf(fp, "%d", &a);
		fscanf(fp, "%d", &r);
		fscanf(fp, "%d", &g);
		fscanf(fp, "%d", &b);
		//std::cout << a << ", " << r << ", " << g << ", " << b << std::endl << "\r";
		Color Outline(a, r, g, b);
		fscanf(fp, "%d", &a);
		fscanf(fp, "%d", &r);
		fscanf(fp, "%d", &g);
		fscanf(fp, "%d", &b);
		//std::cout << a << ", " << r << ", " << g << ", " << b << std::endl << "\r";
		Color C(a, r, g, b);
		if(asset_type == 'S'){
			int x0, x1, y0, y1;
			shapes[asset_count].setAmount(line_count);
			for(int j = 0; j < line_count; ++j){
				fscanf(fp, "%d", &x0);
				fscanf(fp, "%d", &y0);
				fscanf(fp, "%d", &x1);
				fscanf(fp, "%d", &y1);
				//std::cout << x0 << ", " << y0 << ", " << x1 << ", " << y1 << std::endl << "\r";
				shapes[asset_count].addLine(Line(Point(x0, y0), Point(x1, y1)));
			}
			fills[asset_count] = C;
			outlines[asset_count] = Outline;
		}
		asset_count++;
		//std::cout << std::endl << "\r";
	}
    fclose(fp);
	
}

void Render::drawAsset(int idx){
	drawFullShape(shapes[idx], fills[idx], outlines[idx]);
}

void Render::drawFullShape(Shape S, Color C, Color Outline) {
	/* if(!S.isClosed()){
		return;
	} */
	for(int i = 0; i < S.getNeff(); ++i){
		drawLine(S.getLineAt(i), Outline);
	}
	Line L = S.getExtremeLine();
	Point P1(0, 0);
	Point P2(700, 700);
	Line L1(P1, P2);
	//std::cout << L.getP1().getAbsis() << ", " << L.getP1().getOrdinat() << std::endl << "\r";
	//std::cout << L.getP2().getAbsis() << ", " << L.getP2().getOrdinat() << std::endl << "\r";
	for(int y = L.getP1().getOrdinat() + 1; y < L.getP2().getOrdinat(); ++y){
		bool inside = false;
		int meetLine = 0;
		for(int x = L.getP1().getAbsis(); x < L.getP2().getAbsis(); ++x){
			if(meetLine == 1){
				inside = true;
			}
			if(screen.getColorDepth() == 16){
				// x * 2 as every pixel is 2 consecutive bytes
				unsigned int pix_offset = (x + offset_x) * 2 + (y + offset_y) * screen.getLineLength();
				unsigned short out_color = ((Outline.getRed() / 8) * 2048) + ((Outline.getGreen() / 4) * 32) + (Outline.getBlue() / 8);
				if(*((unsigned short*)(screen.getFrameBuffer() + pix_offset)) == out_color){
					meetLine++;
				}
			}
			else if(screen.getColorDepth() == 24){
				// x * 3 as every pixel is 3 consecutive bytes
				unsigned int pix_offset = (x + offset_x) * 3 + (y + offset_y) * screen.getLineLength();
				if(*((char*)(screen.getFrameBuffer() + pix_offset)) == Outline.getBlue() && *((char*)(screen.getFrameBuffer() + pix_offset + 1)) == Outline.getGreen() && *((char*)(screen.getFrameBuffer() + pix_offset + 2)) == Outline.getRed()){
					meetLine++;
				}
			}
			else if(screen.getColorDepth() == 32){
				// x * 2 as every pixel is 4 consecutive bytes
				unsigned int pix_offset = (x + offset_x) * 4 + (y + offset_y) * screen.getLineLength();
				unsigned int out_color = (Outline.getAlpha() << 24) + (Outline.getRed() << 16) + (Outline.getGreen() << 8) + Outline.getBlue();
				if(*((unsigned int*)(screen.getFrameBuffer() + pix_offset)) == out_color){
					meetLine++;
				}
			}
			if(meetLine == 2){
				break;
			}
			if(inside){
				drawPoint(Point(x, y), C);
			}
		}
	}
}

void Render::drawEmptyShape(Shape S, Color Outline){
	for(int i = 0; i < S.getNeff(); ++i){
		drawLine(S.getLineAt(i), Outline);
	}
}

void Render::clearScreen(){
	memset(screen.getFrameBuffer(), 0, (screen.getColorDepth() / 8 * screen.getXRes() * screen.getYRes()));
}

void Render::doMotion(){
	clearScreen();
	for(int i = 0; i < asset_count; ++i){
        drawAsset(i);
    }
	for(;;){
        if(terminal.getIsInput() == State::RECEIVED){
            char input = terminal.getInput();
            switch (input)
            {
                case 'C':
                    offset_x++;
                    break;
                case 'D':
                    offset_x--;
                    break;
                default:
                    break;
            }
			clearScreen();
			for(int i = 0; i < asset_count; ++i){
				drawAsset(i);
			}
            terminal.setIsInput(State::WAITING);
        }
        else if(terminal.getIsInput() == State::STOP){
            terminal.exit();
            break;
        }
    }
}

Input Render::getTerminal(){
	return terminal;
}

Color Render::getBGColor(){
	return BACKGROUND;
}