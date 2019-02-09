/*  Shape.cpp  */

#include "Shape.h"

/** Operator Empat Sekawan **/
Shape::Shape() {
/* Default Constructor with amount = 3  */
    this->amount = 3;
    this->L = new Line[this->amount];
    this->neff = 0;
}

Shape::Shape(unsigned int amount) {
/* Parameterized Constructor */
    try {
        if (amount < 3)
            this->amount = 3;
        else if (amount >=3)
            this->amount = amount;
        else
            throw;
    } catch (...) {
        this->amount = 3;
    }
    
    this->L = new Line[this->amount];
    this->neff = 0;
}

Shape::Shape(const Shape &shape) {
/* Copy Constructor */
    this->amount = shape.getAmount();
    this->L = new Line[this->amount];
    this->neff = shape.getNeff();
    
    for (unsigned int i = 0; i < this->neff; i++)
        this->L[i] = shape.getLineAt(i);
}

Shape::~Shape() {
/* Destructor */
    delete[] this->L;
}


/** Getter and Setter **/
unsigned int Shape::getAmount() const {
    return this->amount;
}

unsigned int Shape::getNeff() const {
    return this->neff;
}

Line Shape::getLineAt(unsigned int idx) const {
    /* The index start from 0, not 1 */
    // Only allowed to set when it is already allocated
    if (idx < this->neff)
        return this->L[idx];
    else
        return Line();
}

void Shape::setLineAt(unsigned int idx, Line line) {
    /* The index start from 0, not 1 */
    // Only allowed to set when it is already allocated
    if (idx < this->neff)
        this->L[idx] = line;
}


/** Function and Procedure **/
void Shape::addLine(Line line) {
    // Only allowed to add when it is not full
    if (this->neff < this->amount) {
        this->L[this->neff] = line;
        this->neff++;
    }
}

bool Shape::isClosed() const {
    bool CLOSED = false;
    for (unsigned int i = 0; i < this->neff; i++) {
        if (i == this->neff - 1)    // At the end of the loop
            if (this->L[i].getP2() != this->L[0].getP1())
                break;
            else
                CLOSED = true;
        else                        // Have not end yet
            if (this->L[i].getP2() == this->L[i+1].getP1())
                break;
    }
    
    return CLOSED;
}
