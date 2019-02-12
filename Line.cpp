/*  Line.cpp  */

#include "Line.h"

/** Operator Empat Sekawan **/
Line::Line() {
/* Default Constructor */
    this->P1 = Point();
    this->P2 = Point();
}

Line::Line(Point P1, Point P2) {
/* Parameterized Constructor */
    this->P1 = P1;
    this->P2 = P2;
}

Line::Line(const Line &L) {
/* Copy Constructor */
    this->P1 = L.getP1();
    this->P2 = L.getP2();
}


/**& getter and Setter **/
Point Line::getP1() const {
/*& get First Point */
    return this->P1;
}

Point Line::getP2() const {
/*& get Second Point */
    return this->P2;
}

void Line::setP1(Point P) {
/* Set First Point by Point */
    this->P1 = P;
}

void Line::setP2(Point P) {
/* Set Second Point by Point */
    this->P2 = P;
}


/** Function and Procedure **/
void Line::moveLeftP1(int x) {
/* Move First Point to Left */
    this->P1.addAbsis(-x);
}

void Line::moveRightP1(int x) {
/* Move First Point to Right */
    this->P1.addAbsis(x);
}

void Line::moveUpP1(int y) {
/* Move First Point to Up */
    this->P1.addOrdinat(-y);
}

void Line::moveDownP1(int y) {
/* Move First Point to Down */
    this->P1.addOrdinat(y);
}

void Line::moveLeftP2(int x) {
/* Move Second Point to Left */
    this->P1.addAbsis(-x);
}

void Line::moveRightP2(int x) {
/* Move Second Point to Right */
    this->P1.addAbsis(x);
}

void Line::moveUpP2(int y) {
/* Move Second Point to Up */
    this->P1.addOrdinat(-y);
}

void Line::moveDownP2(int y) {
/* Move Second Point to Down */
    this->P1.addOrdinat(y);
}
