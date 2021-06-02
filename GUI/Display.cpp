/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Display.cpp
 * @brief
 */

#include "Display.h"
#include "../SIM/Simulation.h"

#include <limits>
#include <iomanip>

Display::Display(int width, int height, int numberOfHumans, int numberOfVampires) :
    Field(width, height, numberOfHumans, numberOfVampires),
    screen(new Humanoid**[height]),
    running(true) {
    for (int y = 0; y < height; ++y)
        screen[y] = new Humanoid*[width];
    this->clear();
}

Display::~Display() {
    // Détruit tous les tableaux alloués dynamiquement
    for (int y = 0; y < this->getHeight(); ++y) {
        delete[] this->screen[y];
    }
    delete[] this->screen;
}

void Display::run() {
    size_t tour = 0;
    bool goNext = true;
    while(this->isRunning()){
        if(goNext) tour = this->nextTurn();
        std::cout << "[" << tour << "] q>uit s>tatistics n>ext:";
        switch(std::cin.peek()) {
            case 'q':
                this->stop();
                break;
            case 'n':
            case '\n':
                goNext = true;
                break;
            case 's': {
                std::cout << "Simulation Config : {" << std::endl;
                std::cout << " width     : " << this->getWidth() << "," << std::endl;
                std::cout << " height    : " << this->getHeight() << "," << std::endl;
                std::cout << " buffy     : a single," << std::endl;
                std::cout << " humans    : " << this->initialHumans() << "," << std::endl;
                std::cout << " vampires  : " << this->initialVampires() << "," << std::endl;
                std::cout << " experience repeated 10000 times" << std::endl;
                std::cout << "}" << std::endl;
                std::cout << "Simulation running..." << std::endl;
                Simulation sim(this, 1);
                std::cout << "Buffy Success Rate : " << sim.getResult() << "%" << std::endl;
                goNext = false;
                break;
            }
            default:
                goNext = false;
                std::cout << "Unknown Command" << std::endl;
        }
        std::cout.flush();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

size_t Display::nextTurn() {
    this->clear();

    // Load humanoid into Display memory
    for(Humanoid* human : this->humanoids){
        Position position = human->getPosition();

        Humanoid* atScreen = this->screen[position.getY() - 1][position.getX() - 1];
        if(atScreen == nullptr || !atScreen->isBuffy()){
            this->screen[position.getY() - 1][position.getX() - 1] = human;
        }
    }

    this->drawLine();

    // Display humanoids into grid view
    for (int y = 0; y < this->getHeight(); ++y) {
        std::cout << "|";
        for (int x = 0; x < this->getWidth(); ++x) {
            Humanoid* current = this->screen[y][x];
            if(current != nullptr){
                std::cout << *current;
            }else{
                std::cout << " ";
            }
        }
        std::cout << "|" << std::endl;
    }

    this->drawLine();

    return Field::nextTurn();
}

bool Display::isRunning() const {
    return this->running;
}

void Display::stop() {
    this->running = false;
}

void Display::clear() {
    for (int y = 0; y < this->getHeight(); ++y)
        for (int x = 0; x < this->getWidth(); ++x)
            screen[y][x] = nullptr;
}

void Display::drawLine() const {
    std::cout << "+" << std::setfill('-') << std::setw (this->getWidth() + 1) << "+" << std::endl;
}