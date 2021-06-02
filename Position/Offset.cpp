/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Offset.cpp
 * @brief Implémentation de la classe Offset
 */

#include "Offset.h"

Offset::Offset(int x, int y)  : x(x), y(y) { }

int Offset::getX() const {
    return x;
}

int Offset::getY() const {
    return y;
}