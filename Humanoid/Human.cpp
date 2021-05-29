//
// Created by stefa on 22.05.2021.
//

#include "Human.h"
#include "../Action/Move.h"

Human::Human(Position position) : Humanoid(position, 1) {
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
