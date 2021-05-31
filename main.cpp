/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file main.cpp
 * @brief
 */

#include "Field.h"
#include "GUI/Display.h"
#include "SIM/Simulation.h"
#include "Utils.h"

#include <iostream>

const int MINIMUM_SIZE = 0;
const int MINIMUM_NUMBER = 0;

void simulationTest(const Display* fieldDisplay, const Field* Field);

using namespace std;

int main(int argc, char** argv) {

    if(argc != 5) {
        cout << "ERROR : you need to provide 4 parameters" << endl;
        return EXIT_FAILURE;
    }

    int width = atoi(argv[1]),
            height = atoi(argv[2]),
            nbHumans = atoi(argv[3]),
            nbVampires = atoi(argv[4]);

    // Check validity
    if(width <= MINIMUM_SIZE || height <= MINIMUM_SIZE) {
        cout << "ERROR : Size of board cannot be null or negative" << endl;
        return EXIT_FAILURE;
    }

    if(nbHumans < MINIMUM_NUMBER || nbVampires < MINIMUM_NUMBER) {
        cout << "ERROR: Number of entities cannot be null" << endl;
        return EXIT_FAILURE;
    }

    Display* fieldDisplay = new Display(width, height, nbHumans, nbVampires);
    fieldDisplay->run();

    delete fieldDisplay;

    return EXIT_SUCCESS;
}

void simulationTest(const Display* fieldDisplay) {

    Field* field = new Field(50, 50, 20, 10);
    Simulation* sim = new Simulation(fieldDisplay, 10000);
    std::cout << "Buffy Success Rate : " << sim->getResult() << std::endl;
    Simulation* sim2 = new Simulation(fieldDisplay, 10000);
    std::cout << "Buffy Success Rate : " << sim2->getResult() << std::endl;
    Simulation* sim3 = new Simulation(field, 10000);
    std::cout << "Buffy Success Rate : " << sim3->getResult() << std::endl;
    delete field;
}