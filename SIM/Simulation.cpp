/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
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

    // Tant qu'on a pas fini la simulation
    while(repeat-- > 0){
        Field field = Field(width, height, numberOfHumans, numberOfVampires);
        while(field.vampiresRemaining() > 0)
            field.nextTurn();
        // S'il reste au moins un humain, 1 succès de plus pour Buffy
        if(field.humansRemaining() > 0)
            numberOfBuffySuccess++;
    }

    // Rapport succès sur le nombre total de simulation
    this->result = (numberOfBuffySuccess / repetitions) * 100;
}

double Simulation::getResult() const {
    return this->result;
}