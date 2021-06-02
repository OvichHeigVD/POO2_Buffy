/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Transform.h
 * @brief Action Transform, classe enfant de Action, permettant de transformer un
 * Humanoid
 */

#ifndef LABO04_TRANSFORM_H
#define LABO04_TRANSFORM_H

#include "Action.h"
#include "../Field.h"

class Transform : public Action {
public:
    /**
     * Constructeur de Transform
     * @param subject - l'humanoid à transformer
     */
    explicit Transform(Human *subject);

    /**
     * Méthode exécutant la transformation de l'humanoid en attribut
     * @param field - un Field
     */
    void execute(Field& field) override;

    /**
     * Destructeur de Transform
     */
    ~Transform() override = default;
};

#endif //LABO04_TRANSFORM_H