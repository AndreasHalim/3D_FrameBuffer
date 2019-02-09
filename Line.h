/*  Line.h  */

#ifndef _LINE_H_
#define _LINE_H_

#include "Point.h"

class Line {
    private:
        Point P1;   // First Point
        Point P2;   // Second Point
        
    public:
        /* Operator Empat Sekawan */
        Line();
        Line(Point P1, Point P2);
        Line(const Line &L);
        
        /* Getter and Setter */
        Point getP1() const;            /* Get First Point */
        Point getP2() const;            /* Get Second Point */
        void setP1(Point P);            /* Set First Point by Point */
        void setP2(Point P);            /* Set Second Point by Point */
        
        /* Function and Procedure */
        void moveLeftP1(int x);         /* Move First Point to Left */
        void moveRightP1(int x);        /* Move First Point to Right */
        void moveUpP1(int y);           /* Move First Point to Up */
        void moveDownP1(int y);         /* Move First Point to Down */
        
        void moveLeftP2(int x);         /* Move Second Point to Left */
        void moveRightP2(int x);        /* Move Second Point to Right */
        void moveUpP2(int y);           /* Move Second Point to Up */
        void moveDownP2(int y);         /* Move Second Point to Down */
};

#endif
