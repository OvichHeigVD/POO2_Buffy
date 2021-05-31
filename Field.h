/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Field.h
 * @brief
 */

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

    /**
     *
     * @param width
     * @param height
     * @param numberOfHumans
     * @param numberOfVampires
     */
    Field(int width, int height, int numberOfHumans, int numberOfVampires);

    /**
     *
     */
    virtual ~Field();

    /**
     *
     * @return
     */
    int getWidth() const;

    /**
     *
     * @return
     */
    int getHeight() const;

    /**
     *
     * @return
     */
    virtual size_t nextTurn();

    /**
     *
     * @return
     */
    Iterator begin();

    /**
     *
     * @return
     */
    Iterator end();

    /**
     *
     * @return
     */
    ConstIterator begin() const;

    /**
     *
     * @return
     */
    ConstIterator end() const;

    /**
     *
     * @return
     */
    int humansRemaining() const;

    /**
     *
     * @return
     */
    int vampiresRemaining() const;

    /**
     *
     * @return
     */
    int initialHumans() const;

    /**
     *
     * @return
     */
    int initialVampires() const;

    /**
     *
     * @tparam T
     * @param from
     * @param minDistance
     * @return
     */
    template <typename T>
    T findClosestHumanoid(const Position& from, double& minDistance) const;

protected:
    std::list<Humanoid*> humanoids;
private:
    /**
     *
     * @return
     */
    Position createPosition() const;

    /**
     *
     * @param vampire
     */
    void addVampire(Vampire* vampire);

    size_t turn;
    const int width, height;
    const int initialNumberOfHumans, initialNumberOfVampires;
    int remainingHumans, remainingVampires;

};

#endif //LABO04_FIELD_H