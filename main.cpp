#include "Field.h"
#include "GUI/Display.h"
#include "SIM/Simulation.h"
#include "Utils.h"

int main() {

    Display* fieldDisplay = new Display(50, 50, 20, 10);
   fieldDisplay->run();

    Field* field = new Field(50, 50, 20, 10);

    Simulation* sim = new Simulation(fieldDisplay, 10000);
    std::cout << "Buffy Success Rate : " << sim->getResult() << std::endl;
    Simulation* sim2 = new Simulation(fieldDisplay, 10000);
    std::cout << "Buffy Success Rate : " << sim2->getResult() << std::endl;
    Simulation* sim3 = new Simulation(field, 10000);
    std::cout << "Buffy Success Rate : " << sim3->getResult() << std::endl;


    return EXIT_SUCCESS;
}
