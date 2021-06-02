/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Movement.h
 * @brief Classe Mouvement qui va générer une direction à prendre pour un humanoid
 */

#ifndef LABO04_MOVEMENT_H
#define LABO04_MOVEMENT_H

#include "Offset.h"
#include "Position.h"

class Movement {
public:
    enum Direction { TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM,
            BOTTOM_LEFT, LEFT, TOP_LEFT, NONE };

    /**
     * Méthode déterminant l'offset à partir d'une Direction
     * @param direction - une direction
     * @return un objet Offset
     */
    static Offset getOffset(Direction direction);

    /**
     * Méthode permettant de générer aléatoirement une direction parmi
     * les 8 possibles
     * @return une direction
     */
    static Movement::Direction random();

    /**
     *
     * @param from - un point de départ
     * @param to - un point d'arrivée
     * @return une direction
     */
    static Direction torwards(Position from, Position to);
};

#endif //LABO04_MOVEMENT_H