/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Human.h
 * @brief Classe Humain, enfant d'Humanoid, permettant de représenter un humain
 */

#ifndef LABO04_HUMAN_H
#define LABO04_HUMAN_H

#include "Humanoid.h"

class Human : public Humanoid {
public:
    /**
     * Constructeur de Human
     * @param position - la position initiale
     */
    explicit Human(Position position);

    /**
     * Destructeur de Human
     */
    ~Human() override = default;

    /**
     * Méthode permettant d'affecter une certaine action à un humain
     * @param where - un Field
     */
    void setAction(const Field& where) override;

    /**
     * Méthode permettant d'exécuter l'action de l'humain
     * @param where - un Field
     */
    void executeAction(Field& where) override;

    /**
     * Méthode permettant de savoir si l'humanoid est un humain ou non
     * @return vrai, un humain est un humain
     */
    bool isHuman() const override;

    /**
     * Méthode permettant d'indiquer que l'humain doit être transformé en vampire
     */
    void transform();

    /**
     * Getter de toBeTransformed
     * @return vrai s'il va être transformé, faux sinon
     */
    bool isTransformed() const;

    /**
     * Méthode s'occupant de l'affichage de Buffy dans le tablea
     * @return 'h' pour 'humain'
     */
    std::string toString() const override;

private:
    bool toBeTransformed;
};

#endif //LABO04_HUMAN_H