/*  Point.h  */

#ifndef _POINT_H_
#define _POINT_H_

class Point {
    private:
        unsigned int x;  // Absis
        unsigned int y;  // Ordinat

    public:
        /* Operator Empat Sekawan */
        Point();
        Point(unsigned int x, unsigned int y);
        Point(const Point &P);

        /* Getter and Setter */
        unsigned int getAbsis() const;
        unsigned int getOrdinat() const;
        
        void setAbsis(unsigned int x);
        void setOrdinat(unsigned int y);
        
        /* Function and Procedure */
        void addAbsis(unsigned int x);
        void addOrdinat(unsigned int y);
        
        /* Operator Overloading */
        bool operator== (const Point &P) const;
        bool operator!= (const Point &P) const;
};

#endif
