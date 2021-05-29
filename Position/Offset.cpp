//
// Created by stefa on 23.05.2021.
//

#include "Offset.h"

Offset::Offset(int x, int y)  : x(x), y(y){}

int Offset::getX() const {
    return x;
}

int Offset::getY() const {
    return y;
}
