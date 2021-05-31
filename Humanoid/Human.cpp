/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Human.cpp
 * @brief Implémentation de la classe Human
 */

#include "Human.h"
#include "../Action/Move.h"

Human::Human(Position position) :
    Humanoid(position, 1),
    toBeTransformed(false) { }

void Human::setAction(const Field& field) {
    this->action = new Move(this, &field, Movement::random());
}

void Human::executeAction(Field& field) {
    if(this->action != nullptr) {
        this->action->execute(field);
        delete this->action;
        this->action = nullptr;
    }
}

bool Human::isHuman() const {
    return true;
}

void Human::transform() {
    this->toBeTransformed = true;
    this->kill();
}

bool Human::isTransformed() const {
    return this->toBeTransformed;
}

std::string Human::toString() const {
    return "h";
}