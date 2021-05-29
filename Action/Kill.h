//
// Created by stefa on 24.05.2021.
//

#ifndef LABO04_KILL_H
#define LABO04_KILL_H

#include "Action.h"
class Field;
class Kill : public Action {
public:
    explicit Kill(Humanoid* humanoid);
    void execute(Field& field) override;
    ~Kill() override = default;
};


#endif //LABO04_KILL_H
