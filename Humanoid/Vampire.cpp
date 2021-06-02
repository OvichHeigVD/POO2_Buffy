/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Vampire.cpp
 * @brief Implémentation de la classe Vampire
 */

#include <limits>
#include <algorithm>
#include "Vampire.h"
#include "../Utils.h"
#include "../Action/Move.h"
#include "../Action/Kill.h"
#include "../Action/Transform.h"

Vampire::Vampire(Position position) : Humanoid(position, 1) {}

Vampire::Vampire(const Human* human) : Humanoid(human->getPosition(), 1) {}

void Vampire::setAction(const Field& field) {
    double minDistance = std::numeric_limits<double>::max();

    // Recherche de l'humain le plus proche
    Human* closestHuman =
            field.findClosestHumanoid<Human*>(this->getPosition(), minDistance);

    // S'il n'y a plus d'humain, ne rien faire
    if(closestHuman != nullptr) {
        // Si l'humain se trouve à une case du vampire, diagonales incluses
        if (minDistance <= 1.42) {
            // 50% de chance de transformer ou de tuer
            if (Utils::randomBool()) {
                this->action = new Kill(closestHuman);
            } else {
                this->action = new Transform(closestHuman);
            }
        } else { // Va s'approcher de l'humain le plus proche
            this->action =
                    new Move(this, &field,
                             Movement::torwards(this->getPosition(),
                                            closestHuman->getPosition()));
        }
    }
}

void Vampire::executeAction(Field& field) {
    // Si une action est définie, l'exécuter puis la détruire
    if(this->action != nullptr){
        this->action->execute(field);
        delete this->action;
        this->action = nullptr;
    }
}

std::string Vampire::toString() const {
    return "V";
}