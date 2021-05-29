//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_HUMAN_H
#define LABO04_HUMAN_H
#include "Humanoid.h"
class Human : public Humanoid{
public:
    explicit Human(Position position);
    void setAction(const Field& where) override;
    void executeAction(Field& where) override;
    std::string toString() const override;
    bool isHuman() const override;
    ~Human() override = default;
};


#endif //LABO04_HUMAN_H
