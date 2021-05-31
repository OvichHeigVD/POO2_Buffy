/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Position.h
 * @brief Classe permettant de créer une position pour l'humanoid
 */

#ifndef LABO04_POSITION_H
#define LABO04_POSITION_H

#include <cstdlib>

class Position {

public:
    /**
     * Constructeur de Position
     * @param x - la coordonnée x
     * @param y - la coordonnée y
     */
    Position(int x, int y);

    /**
     * Getter de x
     * @return la coordonnée x
     */
    int getX() const;

    /**
     * Getter de y
     * @return la coordonnée y
     */
    int getY() const;

    /**
     * Setter  de x
     * @return la coordonnée x
     */
    void setX(int x);

    /**
     * Setter de y
     * @return la coordonnée x
     */
    void setY(int y);

    /**
     * Methode calculant la distance d'un point de départ à un point d'arrivé
     * @param from - le point de départ
     * @param to - le point d'arrivée
     * @return une distance
     */
    static double distance(Position from, Position to);

private:
    int x;
    int y;
};

#endif //LABO04_POSITION_H