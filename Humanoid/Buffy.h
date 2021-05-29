//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_BUFFY_H
#define LABO04_BUFFY_H
#include "Humanoid.h"

class Buffy : public Humanoid{
public:
    explicit Buffy(Position position);
    void setAction(const Field& where) override;
    void executeAction(Field& where) override;
    std::string toString() const override;
    ~Buffy() override = default;
    bool isBuffy() const override;

};


#endif //LABO04_BUFFY_H
