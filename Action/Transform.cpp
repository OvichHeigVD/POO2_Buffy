/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Transform.cpp
 * @brief Implémentation de la classe Move
 */

#include "Transform.h"
#include <algorithm>

Transform::Transform(Human* subject) : Action(subject) { }

void Transform::execute(Field& field) {
    // On veille à transformer un humain vivant
    if(this->subject->isAlive() && this->subject->isHuman()) {
        Field::Iterator it = std::find(field.begin(), field.end(), this->subject);
        if((*it)->isHuman()) {
            Human* human = dynamic_cast<Human*>(*it);
            human->transform();
        }
    }
}