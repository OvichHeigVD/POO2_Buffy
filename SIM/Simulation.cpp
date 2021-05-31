/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Simulation.cpp
 * @brief Implémentation de la classe Simulation
 */

#include "Simulation.h"

Simulation::Simulation(const Field* field, int repetitions) :
    width(field->getWidth()),
    height(field->getHeight()),
    numberOfHumans(field->initialHumans()),
    numberOfVampires(field->initialVampires()),
    repetitions(repetitions), result(0) {
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
    this->result = (numberOfBuffySuccess / repetitions) * 100;
}

double Simulation::getResult() const {
    return this->result;
}

