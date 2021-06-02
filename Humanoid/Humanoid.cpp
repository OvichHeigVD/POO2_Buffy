/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Humanoid.cpp
 * @brief Implementation de la classe Humanoid
 */
#include "Humanoid.h"

Humanoid::Humanoid(Position position, size_t steps) :
    position(position),
    steps(steps),
    action(nullptr),
    futurePosition(nullptr),
    alive(true) { }

Humanoid::~Humanoid() {
    delete this->futurePosition;
    this->futurePosition = nullptr;
}

Position Humanoid::getPosition() const {
    return this->position;
}

void Humanoid::setFuturePosition(int x, int y) {
    delete this->futurePosition;
    this->futurePosition = new Position(x, y);
}

void Humanoid::move() {
    this->position = *this->futurePosition;
    delete this->futurePosition;
    this->futurePosition = nullptr;
}

void Humanoid::kill() {
    this->alive = false;
}

size_t Humanoid::getSteps() const {
    return this->steps;
}

bool Humanoid::isHuman() const {
    return false;
}

bool Humanoid::isBuffy() const {
    return false;
}

bool Humanoid::isAlive() const {
    return this->alive;
}

std::ostream& operator<<(std::ostream &os, const Humanoid &rhs) {
    os << rhs.toString();
    return os;
}