//
// Created by stefa on 24.05.2021.
//

#include "Kill.h"
#include "../Field.h"

Kill::Kill(Humanoid *subject) : Action(subject) {}

void Kill::execute(Field& field) {
    if(this->subject->isAlive()){
        this->subject->kill();
    }
}
