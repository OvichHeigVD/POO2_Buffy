//
// Created by stefa on 22.05.2021.
//

#include "Buffy.h"
#include <limits>
#include <algorithm>
#include "../Action/Move.h"
#include "../Field.h"
#include "../Action/Kill.h"

Buffy::Buffy(Position position) : Humanoid(position, 2) {}

void Buffy::setAction(const Field& field) {
    double minDistance = std::numeric_limits<double>::max();
    Vampire* closestVampire = field.findClosestHumanoid<Vampire*>(this->getPosition(), minDistance);
    if(closestVampire != nullptr){
        if(minDistance <= 1.42){
            this->action = new Kill(closestVampire);
        }else{
            this->action = new Move(this, &field, Movement::torwards(this->getPosition(), closestVampire->getPosition()));
        }
    }else{
        this->action = new Move(this, &field, Movement::random());
    }
}

void Buffy::executeAction(Field& field) {
    if(this->action != nullptr){
        this->action->execute(field);
        delete this->action;
        this->action = nullptr;
    }
}

bool Buffy::isBuffy() const {
    return true;
}

std::string Buffy::toString() const {
    return "B";
}
