//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_VAMPIRE_H
#define LABO04_VAMPIRE_H
#include "Humanoid.h"
class Human;
class Vampire : public Humanoid{
public:
    explicit Vampire(Position position);
    explicit Vampire(const Human* human);
    void setAction(const Field& where) override;
    void executeAction(Field& where) override;
    std::string toString() const override;
    ~Vampire() override = default;
};


#endif //LABO04_VAMPIRE_H
