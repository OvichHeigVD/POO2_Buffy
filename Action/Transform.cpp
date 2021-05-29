//
// Created by stefa on 25.05.2021.
//
#include <algorithm>
#include "Transform.h"

Transform::Transform(Human* subject) : Action(subject){}

void Transform::execute(Field& field) {
    if(this->subject->isAlive() && this->subject->isHuman()){
        Field::Iterator it = std::find(field.begin(), field.end(), this->subject);
        if((*it)->isHuman()){
            Human* human = dynamic_cast<Human*>(*it);
            human->transform();
        }
    }
}
