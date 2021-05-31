/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Movement.h
 * @brief
 */

#ifndef LABO04_MOVEMENT_H
#define LABO04_MOVEMENT_H

#include "Offset.h"
#include "Position.h"

class Movement {
public:
    enum Direction { TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT, TOP_LEFT, NONE };

    /**
     *
     * @param direction
     * @return
     */
    static Offset getOffset(Direction direction);

    /**
     *
     * @return
     */
    static Movement::Direction random();

    /**
     *
     * @param from
     * @param to
     * @return
     */
    static Direction torwards(Position from, Position to);
};

#endif //LABO04_MOVEMENT_H