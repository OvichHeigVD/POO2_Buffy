/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Buffy.h
 * @brief Classe Buffy, enfant d'Humanoid, représentant Buffy, la chasseuse de
 * vampire
 */

#ifndef LABO04_BUFFY_H
#define LABO04_BUFFY_H

#include "Humanoid.h"

class Buffy : public Humanoid {
public:
    /**
     * Constructeur de Buffy
     * @param position - une position initiale
     */
    explicit Buffy(Position position);

    /**
     * Destructeur de Buffy
     */
    ~Buffy() override = default;

    /**
     * Méthode permettant d'affecter une certaine action à Buffy
     * @param where - un Field
     */
    void setAction(const Field& where) override;

    /**
     * Méthode permettant d'exécuter l'action de Buffy
     * @param where - un Field
     */
    void executeAction(Field& where) override;

    /**
     * Méthode permettant de savoir si Buffy est Buffy ou non
     * @return vrai, Buffy est effectivement bien Buffy
     */
    bool isBuffy() const override;

    /**
     * Méthode s'occupant de l'affichage de Buffy dans le tableau
     * @return 'B' représentant Buffy
     */
    std::string toString() const override;
};

#endif //LABO04_BUFFY_H