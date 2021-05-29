//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_FIELD_H
#define LABO04_FIELD_H
#include <iostream>
#include <list>
#include "Position/Position.h"
#include "Humanoid/Humanoid.h"
#include "Humanoid/Human.h"
#include "Humanoid/Vampire.h"
#include "Action/Transform.h"

class Field{

public:
    using List = std::list<Humanoid*>;
    using Iterator = List::iterator;
    using ConstIterator = List::const_iterator;

    Field(int width, int height, int numberOfHumans, int numberOfVampires);
    virtual ~Field();

    int getWidth() const;
    int getHeight() const;
    Position createPosition() const;

    virtual int nextTurn();
    virtual void addVampire(Vampire* vampire);

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

    int humansRemaining() const;
    int vampiresRemaining() const;
    int initialHumans() const;
    int initialVampires() const;

    template <typename T>
    T findClosestHumanoid(const Position& from, double& minDistance) const;

protected:
    std::list<Humanoid*> humanoids;

private:
    int turn;
    const int width, height;
    const int initialNumberOfHumans, initialNumberOfVampires;
    int remainingHumans, remainingVampires;

};

#endif //LABO04_FIELD_H
