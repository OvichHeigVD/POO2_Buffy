/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Offset.cpp
 * @brief
 */

#include "Offset.h"

Offset::Offset(int x, int y)  : x(x), y(y){}

int Offset::getX() const {
    return x;
}

int Offset::getY() const {
    return y;
}
