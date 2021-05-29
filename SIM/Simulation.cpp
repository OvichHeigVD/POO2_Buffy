//
// Created by stefa on 28.05.2021.
//

#include "Simulation.h"

Simulation::Simulation(const Field* field, int repetitions) :
width(field->getWidth()),
height(field->getHeight()),
numberOfHumans(field->initialHumans()),
numberOfVampires(field->initialVampires()),
repetitions(repetitions), result(0){
    this->run();
}

void Simulation::run() {
    double numberOfBuffySuccess = 0;
    int repeat = repetitions;

    while(repeat-- > 0){
        Field field = Field(width, height, numberOfHumans, numberOfVampires);
        while(field.vampiresRemaining() > 0)
            field.nextTurn();
        if(field.humansRemaining() > 0)
            numberOfBuffySuccess++;
    }
    this->result = (numberOfBuffySuccess / repetitions);
}

double Simulation::getResult() const {
    return this->result;
}

