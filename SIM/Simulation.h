/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Simulation.h
 * @brief Classe permettant de simuler sans interface le programme
 */

#ifndef LABO04_SIMULATION_H
#define LABO04_SIMULATION_H

#include "../Field.h"

class Simulation {
public:
    /**
     * Constructeur de Simulation
     * @param field - un Field
     * @param repetitions - le nombre de simulations à effectuer
     */
    Simulation(const Field* field, int repetitions);

    /**
     * Méthode permettant de connaître le pourcentage de réussite de Buffy
     * @return un pourcentage de succès
     */
    double getResult() const;

private:
    /**
     * Méthode lançant la simulation
     */
    void run();

    const int width, height, numberOfHumans, numberOfVampires, repetitions;
    double result;
};

#endif //LABO04_SIMULATION_H