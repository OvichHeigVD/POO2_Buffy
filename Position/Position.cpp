/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Position.cpp
 * @brief Implémentation de Position
 */

#include "Position.h"

#include <cmath>

Position::Position(int x, int y) : x(x), y(y) { }

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

double Position::distance(Position from, Position to) {
    // Théorème de Pythagore
    return sqrt(pow(to.getX() - from.getX(), 2) +
                    pow(to.getY() - from.getY(), 2) * 1.0);
}