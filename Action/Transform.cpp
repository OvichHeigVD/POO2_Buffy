//
// Created by stefa on 25.05.2021.
//
#include <algorithm>
#include "Transform.h"

Transform::Transform(Human* subject) : Action(subject){}

void Transform::execute(Field& field) {
    if(this->subject->isAlive() && this->subject->isHuman()){
        Vampire* vampire = new Vampire((Human*) this->subject);
        Field::Iterator it = std::find(field.begin(), field.end(), this->subject);
        (*it)->kill();
        field.addVampire(vampire);
    }
}
