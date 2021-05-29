//
// Created by stefa on 23.05.2021.
//

#ifndef LABO04_MOVEMENT_H
#define LABO04_MOVEMENT_H


#include "Offset.h"
#include "Position.h"

class Movement {
public:
    enum Direction { TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT, TOP_LEFT, NONE };

    static Offset getOffset(Direction direction);
    static Movement::Direction random();
    static Direction torwards(Position from, Position to);

};


#endif //LABO04_MOVEMENT_H
