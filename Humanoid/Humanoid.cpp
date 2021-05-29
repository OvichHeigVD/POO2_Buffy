//
// Created by stefa on 22.05.2021.
//

#include "Humanoid.h"

Humanoid::Humanoid(Position position, size_t steps) :
    position(position),
    steps(steps),
    action(nullptr),
    futurePosition(nullptr),
    alive(true) {}

std::ostream& operator<<(std::ostream &os, const Humanoid &rhs) {
    os << rhs.toString();
    return os;
}

bool Humanoid::isAlive() const {
    return this->alive;
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
    this->futurePosition = nullptr;
}

size_t Humanoid::getSteps() const {
    return this->steps;
}

bool Humanoid::isHuman() const {
    return false;
}

Humanoid::~Humanoid() {
    delete this->futurePosition;
    this->futurePosition = nullptr;
}

void Humanoid::kill() {
    this->alive = false;
}

bool Humanoid::isBuffy() const {
    return false;
}
