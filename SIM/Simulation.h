/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Simulation.h
 * @brief
 */

#ifndef LABO04_SIMULATION_H
#define LABO04_SIMULATION_H

#include "../Field.h"

class Simulation {
public:
    /**
     *
     * @param field
     * @param repetitions
     */
    Simulation(const Field* field, int repetitions);

    /**
     *
     * @return
     */
    double getResult() const;

private:
    /**
     *
     */
    void run();

    const int width, height, numberOfHumans, numberOfVampires, repetitions;
    double result;
};

#endif //LABO04_SIMULATION_H