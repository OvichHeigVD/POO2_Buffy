//
// Created by stefa on 23.05.2021.
//

#ifndef LABO04_POSITION_H
#define LABO04_POSITION_H

#include <cstdlib>

class Position{
    int x;
    int y;
public:
    Position(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    static double distance(Position from, Position to);
};

#endif //LABO04_POSITION_H
