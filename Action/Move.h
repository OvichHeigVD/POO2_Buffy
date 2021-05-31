/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Move.h
 * @brief Action Move, classe enfant de Action, permettant de déplacer un Humanoid
 */

#ifndef LABO04_MOVE_H
#define LABO04_MOVE_H

#include "Action.h"
#include "../Position/Movement.h"
#include "../Position/Position.h"

class Field;

class Move : public Action {
public:
    /**
     * Constructeur de Move
     * @param humanoid - un Humanoid
     * @param field - un Field
     * @param direction - une direction à suivre
     */
    Move(Humanoid* humanoid, const Field* field, Movement::Direction direction);

    /**
     * Méthode exécutant le déplacement d'un Humanoid sur un Field
     * @param field - un Field
     */
    void execute(Field& field) override;

    /**
     * Destructeur de Move
     */
    ~Move() override = default;
};

#endif //LABO04_MOVE_H