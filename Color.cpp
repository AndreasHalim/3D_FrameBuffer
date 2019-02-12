/*  Color.cpp */

#include "Color.h"

/** Operator Empat Sekawan **/
Color::Color() {
/* Default Constructor */
    this->a = 255;
    this->r = 255;
    this->g = 255;
    this->b = 255;
}

Color::Color(unsigned char a, unsigned char r, unsigned char g, unsigned char b) {
/* Parameterized Constructor */
    this->a = a;
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::Color(const Color &C) {
/* Copy Constructor */
    this->a = C.getAlpha();
    this->r = C.getRed();
    this->g = C.getGreen();
    this->b = C.getBlue();
}


/**& getter and Setter **/
unsigned char Color::getAlpha() const {
    return this->a;
}

unsigned char Color::getRed() const {
    return this->r;
}

unsigned char Color::getGreen() const {
    return this->g;
}

unsigned char Color::getBlue() const {
    return this->b;
}


void Color::setAlpha(unsigned char a) {
    this->a = a;
}

void Color::setRed(unsigned char r) {
    this->r = r;
}

void Color::setGreen(unsigned char g) {
    this->g = g;
}

void Color::setBlue(unsigned char b) {
    this->b = b;
}


/** Function and Procedure **/
/* Visibility Procedure */
void Color::makeVisible() {
    this->a = 255;
}

void Color::makeInvisible() {
    this->a = 0;
}

void Color::makeHalfInvisible() {
    this->a = 127;
}

/* Black and White Procedure */
void Color::makeBlack() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

void Color::makeGray() {
/* Medium Gray or Cool Gray 7 */
    this->r = 134;
    this->g = 136;
    this->b = 138;
}

void Color::makeWhite() {
    this->r = 255;
    this->g = 255;
    this->b = 255;
}

/* Make Full Color Procedure */
void Color::makeRed() {
    this->r = 255;
    this->g = 0;
    this->b = 0;
}

void Color::makeGreen() {
    this->r = 0;
    this->g = 255;
    this->b = 0;
}

void Color::makeBlue() {
    this->r = 0;
    this->g = 0;
    this->b = 255;
}

/* Increase procedure to increase the value */
void Color::increaseAlpha(unsigned char a) {
    this->a += a;
}

void Color::increaseRed(unsigned char r) {
    this->r += r;
}

void Color::increaseGreen(unsigned char g) {
    this->g += g;
}

void Color::increaseBlue(unsigned char b) {
    this->b += b;
}

/* Decrease procedure to reduce the value */
void Color::decreaseAlpha(unsigned char a) {
    this->a -= a;
}

void Color::decreaseRed(unsigned char r) {
    this->r -= r;
}

void Color::decreaseGreen(unsigned char g) {
    this->g -= g;
}

void Color::decreaseBlue(unsigned char b) {
    this->b -= b;
}
