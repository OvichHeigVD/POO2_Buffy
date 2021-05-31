/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Offset.h
 * @brief Classe Offset qui va calculer le déplacement sous forme de coordonnées
 */

#ifndef LABO04_OFFSET_H
#define LABO04_OFFSET_H

class Offset {
    int x, y;
public:
    /**
     * Constructeur d'Offset
     * @param x - la coordonnée x
     * @param y - la coordonnée y
     */
    Offset(int x, int y);

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
};

#endif //LABO04_OFFSET_H