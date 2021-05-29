//
// Created by stefa on 23.05.2021.
//
#include <cstdlib>
#include "Move.h"
#include "../Field.h"

Move::Move(Humanoid* humanoid, const Field* field, Movement::Direction direction) : Action(humanoid){

    // calculate x, y offset for movement in appropriate direction
    Offset offset = Movement::getOffset(direction);
    int offsetX = offset.getX() * this->subject->getSteps();
    int offsetY = offset.getY() * this->subject->getSteps();

    // check field bounds after applying offset
    Position initialPosition = this->subject->getPosition();
    if(initialPosition.getX() + offsetX < 1)         offsetX = 0;
    if(initialPosition.getY() + offsetY < 1)         offsetY = 0;
    if(initialPosition.getX() + offsetX > field->getWidth())  offsetX = 0;
    if(initialPosition.getY() + offsetY > field->getHeight()) offsetY = 0;

    // store the future position for next executeAction
    humanoid->setFuturePosition(
    initialPosition.getX() + offsetX,
    initialPosition.getY() + offsetY
    );
}

void Move::execute(Field& field) {
    this->subject->move();
}

