/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Buffy.cpp
 * @brief Implémentation de la classe Buffy
 */

#include "Buffy.h"
#include "../Action/Move.h"
#include "../Field.h"
#include "../Action/Kill.h"

#include <limits>
#include <algorithm>

Buffy::Buffy(Position position) : Humanoid(position, 2) { }

void Buffy::setAction(const Field& field) {
    double minDistance = std::numeric_limits<double>::max();

    // Cherche le vampire le plus proche
    Vampire* closestVampire =
            field.findClosestHumanoid<Vampire*>(this->getPosition(), minDistance);

    if(closestVampire != nullptr) {
        // Si le vampire se trouve à une case de Buffy, diagonales incluses
        if(minDistance <= 1.42) {
            this->action = new Kill(closestVampire);
        } else { // Sinon se déplace sur la grille
            this->action = new Move(this, &field,Movement::torwards(
                    this->getPosition(), closestVampire->getPosition()));
        }
    } else { // Dans le cas où il y aurait plus de vampire, se balader
        this->action = new Move(this, &field, Movement::random());
    }
}

void Buffy::executeAction(Field& field) {
    // Si une action est définie, l'exécuter puis la détruire
    if(this->action != nullptr) {
        this->action->execute(field);
        delete this->action;
        this->action = nullptr;
    }
}

bool Buffy::isBuffy() const {
    return true;
}

std::string Buffy::toString() const {
    return "B";
}
