/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Kill.cpp
 * @brief Implémentation de la classe Kill
 */

#include "Kill.h"
#include "../Field.h"

Kill::Kill(Humanoid *subject) : Action(subject) { }

void Kill::execute(Field& field) {
    // Si vivant, le tuer
    if(this->subject->isAlive()) {
        this->subject->kill();
    }
}