/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Movement.cpp
 * @brief Implementation de la classe Movement
 */

#include "Movement.h"
#include "../Utils.h"

Offset Movement::getOffset(Movement::Direction direction) {
    switch(direction){
        case Movement::Direction::TOP :
            return {0, -1};
        case Movement::Direction::TOP_RIGHT :
            return {1, -1};
        case Movement::Direction::RIGHT :
            return {1, 0};
        case Movement::Direction::BOTTOM_RIGHT :
            return {1, 1};
        case Movement::Direction::BOTTOM :
            return {0, 1};
        case Movement::Direction::BOTTOM_LEFT :
            return {-1, 1};
        case Movement::Direction::LEFT :
            return {-1, 0};
        case Movement::Direction::TOP_LEFT :
            return {-1, -1};
        case Movement::Direction::NONE :
        default:
            return {0,0};
    }
}

Movement::Direction Movement::random() {
    return (Movement::Direction) Utils::randomInt(0,7);
}

Movement::Direction Movement::torwards(Position from, Position to) {

    if(to.getY() == from.getY() && to.getX() < from.getX())
        return Movement::Direction::LEFT;
    if(to.getY() == from.getY() && to.getX() > from.getX())
        return Movement::Direction::RIGHT;
    if(to.getX() == from.getX() && to.getY() < from.getY())
        return Movement::Direction::TOP;
    if(to.getX() == from.getX() && to.getY() > from.getY())
        return Movement::Direction::BOTTOM;

    if(to.getX() < from.getX() && to.getY() < from.getY())
        return Movement::Direction::TOP_LEFT;
    if(to.getX() > from.getX() && to.getY() < from.getY())
        return Movement::Direction::TOP_RIGHT;

    if(to.getX() < from.getX() && to.getY() > from.getY())
        return Movement::Direction::BOTTOM_LEFT;
    if(to.getX() > from.getX() && to.getY() > from.getY())
        return Movement::Direction::BOTTOM_RIGHT;

    return Movement::Direction::NONE;
}