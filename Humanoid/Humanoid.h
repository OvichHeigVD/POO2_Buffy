/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Humanoid.h
 * @brief Classe abstraite Humanoid permettant de représenter les différentes
 * entités du programme (Vampire, Human, Buffy)
 */

#ifndef LABO04_HUMANOID_H
#define LABO04_HUMANOID_H

#include "../Position/Position.h"
#include "../Action/Action.h"

#include <iostream>
#include <cstddef>

class Field;

class Humanoid {
    friend class Move;
    /**
     * Surcharge de l'opérateur de flux de sortie
     * @param os - un ostream
     * @param rhs - un Humanoid
     * @return une sortie formattée
     */
    friend std::ostream& operator<<(std::ostream& os, const Humanoid& rhs);

protected:
    Action* action;
    size_t steps;

public:
    /**
     * Constructeur d'un Humanoid
     * @param position - position initiale sur le Field
     * @param steps - nombre de cases de déplacement
     */
    Humanoid(Position position, size_t steps);

    /**
     * Destructeur d'Humanoid
     */
    virtual ~Humanoid();

     /**
     * Méthode abstraite permettant d'affecter une certaine action
     * @param where - un Field
     */
    virtual void setAction(const Field& where) = 0;

    /**
     * Méthode abstraite permettant d'exécuter une certaine action
     * @param where - un Field
     */
    virtual void executeAction(Field& where) = 0;

    /**
     * Getter de position
     * @return la position de l'Humanoid
     */
    Position getPosition() const;


    /**
     * Méthode permettant d'affecter la future position à la position actuelle
     */
    void move();


    /**
     * Setter de alive (le modifie à faux)
     */
    void kill();

    /**
     * Getter de steps, le nombre de pas à effectuer chaque tour
     * @return le nombre de pas
     */
    size_t getSteps() const;

    /**
     * Méthode permettant de savoir si l'humanoid est un humain ou non
     * @return faux par défaut
     */
    virtual bool isHuman() const;

    /**
     * Méthode permettant de savoir si l'humanoid est Buffy ou non
     * @return faux par défaut
     */
    virtual bool isBuffy() const;

    /**
     * Méthode permettant de savoir si l'humanoid est vivant ou non
     * @return vrai si en vie, faux sinon
     */
    bool isAlive() const;

    /**
     * Méthode abstraite s'occupant de l'affichage de l'humanoid dans le tableau
     * @return un caractère sous forme de string
     */
    virtual std::string toString() const = 0;
private:

    /**
     * Setter de la future position de l'humanoid
     * @param x - la coordonnée x
     * @param y - la coordonnée y
     */
    void setFuturePosition(int x, int y);
private:
    Position position;
    Position* futurePosition;
    bool alive;
};

#endif //LABO04_HUMANOID_H