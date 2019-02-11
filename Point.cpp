/*  Point.cpp  */

#include "Point.h"

/** Operator Empat Sekawan **/
Point::Point() {
/* Default Constructor */
    this->x = 0;
    this->y = 0;
}

Point::Point(unsigned int x, unsigned int y) {
/* Parameterized Constructor */
    this->x = x;
    this->y = y;
}
    
Point::Point(const Point &P) {
/* Copy Constructor */
    this->x = P.getAbsis();
    this->y = P.getOrdinat();
}


/** Getter and Setter **/
unsigned int Point::getAbsis() const {
    return this->x;
}

unsigned int Point::getOrdinat() const {
    return this->y;
}

void Point::setAbsis(unsigned int x) {
    this->x = x;
}

void Point::setOrdinat(unsigned int y) {
    this->y = y;
}

/** Function and Procedure **/
void Point::addAbsis(unsigned int x) {
    this->x += x;
}

void Point::addOrdinat(unsigned int y) {
    this->y += y;
}

/** Operator Overloading **/
bool Point::operator== (const Point &P) const {
    return ((this->x == P.getAbsis()) and (this->y == P.getOrdinat()));
}

bool Point::operator!= (const Point &P) const {
    return ((this->x != P.getAbsis()) or (this->y != P.getOrdinat()));
}
