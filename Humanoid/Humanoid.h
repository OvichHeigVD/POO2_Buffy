//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_HUMANOID_H
#define LABO04_HUMANOID_H

#include <iostream>
#include <cstddef>
#include "../Position/Position.h"
#include "../Action/Action.h"
class Field;
class Humanoid {
    friend std::ostream& operator<<(std::ostream& os, const Humanoid& rhs);
private:
    Position position;
    Position* futurePosition;
    bool alive;
protected:
    Action* action;
    size_t steps;
public:
    Humanoid(Position position, size_t steps);
    virtual std::string toString() const = 0;
    virtual void setAction(const Field& where) = 0;
    virtual void executeAction(Field& where) = 0;
    virtual bool isHuman() const;
    virtual bool isBuffy() const;
    virtual ~Humanoid();
    bool isAlive() const;
    void kill();
    Position getPosition() const;
    void setFuturePosition(int x, int y);
    void move();
    size_t getSteps() const;

};


#endif //LABO04_HUMANOID_H
