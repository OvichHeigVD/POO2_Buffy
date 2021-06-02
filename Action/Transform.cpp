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
        Human* humain = dynamic_cast<Human*>(this->subject);
        if(humain != nullptr && !humain->isTransformed())
            humain->transform();
    }
}