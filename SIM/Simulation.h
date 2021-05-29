//
// Created by stefa on 28.05.2021.
//

#ifndef LABO04_SIMULATION_H
#define LABO04_SIMULATION_H
#include "../Field.h"

class Simulation {
public:
    Simulation(const Field* field, int repetitions);
    double getResult() const;
private:
    void run();
private:
    const int width, height, numberOfHumans, numberOfVampires, repetitions;
    double result;
};


#endif //LABO04_SIMULATION_H
