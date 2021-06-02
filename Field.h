/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Field.h
 * @brief Classe gérant la grille (Field)
 */

#ifndef LABO04_FIELD_H
#define LABO04_FIELD_H

#include "Position/Position.h"
#include "Humanoid/Humanoid.h"
#include "Humanoid/Human.h"
#include "Humanoid/Vampire.h"
#include "Action/Transform.h"

#include <iostream>
#include <list>

class Field {

public:
    // Alias
    using List = std::list<Humanoid*>;
    using Iterator = List::iterator;
    using ConstIterator = List::const_iterator;

    /**
     * Constructeur de Field, prenant les arguments donnés par l'utilisateur
     * comme paramètre
     * @param width - une largeur
     * @param height - une hauteur
     * @param numberOfHumans - le nombre d'humains
     * @param numberOfVampires - le nombre de vampires
     */
    Field(int width, int height, int numberOfHumans, int numberOfVampires);

    /**
     * Destructeur de Vampire
     */
    virtual ~Field();

    /**
     * Méthode permettant de simuler un tour du programme
     * @return le chiffre du prochain tour
     */
    virtual size_t nextTurn();

    /**
     * Getter de la largeur
     * @return la largeur
     */
    int getWidth() const;

    /**
     * Getter de la hauteur
     * @return - la hauteur
     */
    int getHeight() const;

    /**
     * Méthode permettant d'avoir un itérateur en début de liste
     * (pour les méthodes const)
     * @return un ConstIterator
     */
    ConstIterator begin() const;

    /**
     * Méthode permettant d'avoir un itérateur en fin de liste
     * (pour les méthodes const)
     * @return un ConstIterator
     */
    ConstIterator end() const;

    /**
     * Méthode permettant de savoir combien d'humains sont restants
     * @return le nombre restant d'humains
     */
    int humansRemaining() const;

    /**
     * Méthode permettant de savoir combien de vampires sont restants
     * @return le nombre restant de vampires
     */
    int vampiresRemaining() const;

    /**
     * Getter du nombre initial d'humains
     * @return le nombre initial d'humains
     */
    int initialHumans() const;

    /**
     * Getter du nombre initial de vampires
     * @return le nombre initial de vampires
     */
    int initialVampires() const;

    /**
     * Méthode cherchant l'humanoid le plus proche
     * @tparam T un type Template pouvant être un Vampire ou Buffy
     * @param from - position courante
     * @param minDistance - distance minimale
     * @return l'humanoid le plus proche
     */
    template <typename T>
    T findClosestHumanoid(const Position& from, double& minDistance) const;

private:
    /**
    * Méthode permettant d'avoir un itérateur en début de liste
    * @return un Iterator
    */
    Iterator begin();

    /**
     * Méthode permettant d'avoir un itérateur en fin de liste
     * @return un Iterator
     */
    Iterator end();

    /**
     * Méthode créant une nouvelle position pour un Humanoid
     * @return une Position de coordonnée x et y
     */
    Position createPosition() const;

    /**
     * Méthode ajoutant un vampire dans la simulation (après qu'un humain ait été
     * transformé)
     * @param vampire - un objet Vampire
     */
    void addVampire(Vampire* vampire);

    size_t turn;
    const int width, height;
    const int initialNumberOfHumans, initialNumberOfVampires;
    int remainingHumans, remainingVampires;
    std::list<Humanoid*> humanoids;
};

#endif //LABO04_FIELD_H