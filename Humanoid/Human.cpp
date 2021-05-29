//
// Created by stefa on 22.05.2021.
//

#include "Human.h"
#include "../Action/Move.h"

Human::Human(Position position) : Humanoid(position, 1), toBeTransformed(false) {
}

void Human::setAction(const Field& field) {
    this->action = new Move(this, &field, Movement::random());
}

void Human::executeAction(Field& field) {
    this->action->execute(field);
    delete this->action;
    this->action = nullptr;
}

bool Human::isHuman() const {
    return true;
}

std::string Human::toString() const {
    return "h";
}

bool Human::isTranform() const {
    return this->toBeTransformed;
}

void Human::transform() {
    this->toBeTransformed = true;
    this->kill();
}
