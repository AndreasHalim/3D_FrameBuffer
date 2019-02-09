/*  Point.h  */

#ifndef _POINT_H_
#define _POINT_H_

class Point {
    private:
        unsigned int x;  // Absis
        unsigned int y;  // Ordinat
        unsigned int z;  // Applicate

    public:
        /* Operator Empat Sekawan */
        Point();
        Point(unsigned int x, unsigned int y, unsigned int z);
        Point(const Point &P);

        /* Getter and Setter */
        unsigned int getAbsis() const;
        unsigned int getOrdinat() const;
        unsigned int getApplicate() const;
        
        void setAbsis(unsigned int x);
        void setOrdinat(unsigned int y);
        void setApplicate(unsigned int z);
        
        /* Function and Procedure */
        void addAbsis(unsigned int x);
        void addOrdinat(unsigned int y);
        void addApplicate(unsigned int z);
        
        /* Operator Overloading */
        bool operator== (const Point &P) const;
        bool operator!= (const Point &P) const;
};

#endif
