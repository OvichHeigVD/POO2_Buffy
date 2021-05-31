/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Position.cpp
 * @brief
 */

#include "Position.h"
#include <cmath>

Position::Position(int x, int y) : x(x), y(y){}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int newX) {
    this->x = newX;
}

void Position::setY(int newY) {
    this->y = newY;
}

double Position::distance(Position from, Position to) {
        return sqrt(pow(to.getX() - from.getX(), 2) +
                    pow(to.getY() - from.getY(), 2) * 1.0);
}

