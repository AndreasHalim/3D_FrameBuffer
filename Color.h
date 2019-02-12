/*  Color.h */

#ifndef _COLOR_H
#define _COLOR_H

class Color {
    private:
    /* Range of number 0 to 255 */
        unsigned char a;    // Alpha: Opacity or Transparency
        unsigned char r;    // Red
        unsigned char g;    // Green
        unsigned char b;    // Blue
        
    public:
        /* Operator Empat Sekawan */
        Color();
        Color(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
        Color(const Color &C);
        
        /*& getter and Setter */
        unsigned char getAlpha() const;
        unsigned char getRed() const;
        unsigned char getGreen() const;
        unsigned char getBlue() const;
        
        void setAlpha(unsigned char a);
        void setRed(unsigned char r);
        void setGreen(unsigned char g);
        void setBlue(unsigned char b);
        
        /* Function and Procedure */
        void makeVisible();
        void makeInvisible();
        void makeHalfInvisible();
        
        void makeBlack();
        void makeGray();
        void makeWhite();
        
        void makeRed();
        void makeGreen();
        void makeBlue();
        
        void increaseAlpha(unsigned char a);
        void increaseRed(unsigned char r);
        void increaseGreen(unsigned char g);
        void increaseBlue(unsigned char b);
        
        void decreaseAlpha(unsigned char a);
        void decreaseRed(unsigned char r);
        void decreaseGreen(unsigned char g);
        void decreaseBlue(unsigned char b);
};

#endif
