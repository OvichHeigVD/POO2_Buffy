//
// Created by stefa on 23.05.2021.
//

#ifndef LABO04_ACTION_H
#define LABO04_ACTION_H

class Field;
class Humanoid;
class Action {
protected:
    explicit Action(Humanoid* subject);
    Humanoid* subject;
public:
    virtual void execute(Field& field) = 0;
    virtual ~Action() = default;
};


#endif //LABO04_ACTION_H
