/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Vampire.h
 * @brief Classe Vampire, enfant d'Humanoid, permettant de représenter un vampire
 */

#ifndef LABO04_VAMPIRE_H
#define LABO04_VAMPIRE_H

#include "Humanoid.h"

class Human;

class Vampire : public Humanoid {
public:
    /**
     * Constructeur de Vampire
     * @param position - une position initale
     */
    explicit Vampire(Position position);

    /**
     * Constructeur de Vampire
     * @param human - un humain qui va être transformé
     */
    explicit Vampire(const Human* human);

    /**
     * Destructeur de Vampire
     */
    ~Vampire() override = default;

    /**
     * Méthode permettant d'affecter une certaine action à un vampire
     * @param where - un Field
     */
    void setAction(const Field& where) override;

    /**
     * Méthode permettant d'exécuter l'action d'un vampire
     * @param where - un Field
     */
    void executeAction(Field& where) override;

    /**
     * Méthode s'occupant de l'affichage d'un vampire dans le tableau
     * @return 'V' représentant un vampire
     */
    std::string toString() const override;
};

#endif //LABO04_VAMPIRE_H