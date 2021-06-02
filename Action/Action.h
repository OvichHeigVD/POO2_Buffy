/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Action.h
 * @brief Classe abstraite Action que peuvent faire les Humanoids (Se déplacer,
 * Transformer ou Tuer).
 */

#ifndef LABO04_ACTION_H
#define LABO04_ACTION_H

class Field;
class Humanoid;

class Action {
protected:
    /**
     * Constructeur de Action
     * @param subject - un Humanoid
     */
    explicit Action(Humanoid* subject);

    Humanoid* subject;
public:
    /**
     * Méthode abstraite exécutant le comportement d'une action
     * @param field - un Field
     */
    virtual void execute(Field& field) = 0;

    /**
     * Destructeur de Action
     */
    virtual ~Action() = default;
};

#endif //LABO04_ACTION_H