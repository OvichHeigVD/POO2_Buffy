//
// Created by stefa on 23.05.2021.
//

#ifndef LABO04_MOVE_H
#define LABO04_MOVE_H

#include "Action.h"
#include "../Position/Movement.h"
#include "../Position/Position.h"
class Field;
class Move : public Action{
public:
    Move(Humanoid* humanoid, const Field* field, Movement::Direction direction);
    void execute(Field& field) override;
    ~Move() override = default;
};


#endif //LABO04_MOVE_H
