//
// Created by stefa on 25.05.2021.
//

#ifndef LABO04_TRANSFORM_H
#define LABO04_TRANSFORM_H

#include "Action.h"
#include "../Field.h"

class Transform : public Action {
public:
    explicit Transform(Human *subject);
    void execute(Field& field) override;
    ~Transform() override = default;
};


#endif //LABO04_TRANSFORM_H
