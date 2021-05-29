//
// Created by stefa on 22.05.2021.
//
#include <limits>
#include <algorithm>
#include "Vampire.h"
#include "../Utils.h"
#include "../Action/Move.h"
#include "../Action/Kill.h"
#include "../Action/Transform.h"

Vampire::Vampire(Position position) : Humanoid(position, 1) {}

Vampire::Vampire(const Human* human) : Humanoid(human->getPosition(), 1) {}

void Vampire::setAction(const Field& field) {
    double minDistance = std::numeric_limits<double>::max();
    Human* closestHuman = field.findClosestHumanoid<Human*>(this->getPosition(), minDistance);
    if(closestHuman != nullptr) {
        if (minDistance <= 1.42) {
            if (Utils::randomBool()) {
                this->action = new Kill(closestHuman);
            } else {
                this->action = new Transform(closestHuman);
            }
        } else {
            this->action = new Move(this, &field,
                                    Movement::torwards(this->getPosition(), closestHuman->getPosition()));
        }
    }
}

void Vampire::executeAction(Field& field) {
    if(this->action != nullptr){
        this->action->execute(field);
        delete this->action;
        this->action = nullptr;
    }
}

std::string Vampire::toString() const {
    return "V";
}
