/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Move.cpp
 * @brief Implémentation de la classe Move
 */

#include "Move.h"
#include "../Field.h"

Move::Move(Humanoid* humanoid, const Field* field, Movement::Direction direction) :
    Action(humanoid) {

    // calcule l'offset x, y du mouvement dans la direction appropriée
    Offset offset = Movement::getOffset(direction);
    int offsetX = offset.getX() * this->subject->getSteps();
    int offsetY = offset.getY() * this->subject->getSteps();

    // vérification des limites du Field après avoir appliqué l'offset
    Position initialPosition = this->subject->getPosition();

    if(initialPosition.getX() + offsetX < 1)         offsetX = 0;
    if(initialPosition.getY() + offsetY < 1)         offsetY = 0;

    if(initialPosition.getX() + offsetX > field->getWidth())  offsetX = 0;
    if(initialPosition.getY() + offsetY > field->getHeight()) offsetY = 0;

    // stocke la future position pour le prochain executeAction
    humanoid->setFuturePosition(
            initialPosition.getX() + offsetX,initialPosition.getY() + offsetY);
}

void Move::execute(Field& field) {
    this->subject->move();
}