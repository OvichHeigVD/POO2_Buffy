/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Kill.h
 * @brief Action Kill, classe enfant de Action, permettant de tuer un Humanoid
 */

#ifndef LABO04_KILL_H
#define LABO04_KILL_H

#include "Action.h"

class Field;

class Kill : public Action {
public:
    /**
     * Constructeur de Kill
     * @param humanoid - un Humanoid
     */
    explicit Kill(Humanoid* humanoid);

    /**
     * Méthode exécutant l'action Kill
     * (va permettre de tuer l'humanoid en attribut)
     * @param field - un Field
     */
    void execute(Field& field) override;

    /**
     * Destructeur de Kill
     */
    ~Kill() override = default;
};

#endif //LABO04_KILL_H