/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Position.h
 * @brief
 */

#ifndef LABO04_POSITION_H
#define LABO04_POSITION_H

#include <cstdlib>

class Position {

public:
    /**
     *
     * @param x
     * @param y
     */
    Position(int x, int y);

    /**
     *
     * @return
     */
    int getX() const;

    /**
     *
     * @return
     */
    int getY() const;

    /**
     *
     * @param x
     */
    void setX(int x);

    /**
     *
     * @param y
     */
    void setY(int y);

    /**
     *
     * @param from
     * @param to
     * @return
     */
    static double distance(Position from, Position to);

private:
    int x;
    int y;
};

#endif //LABO04_POSITION_H