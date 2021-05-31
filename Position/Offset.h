/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Offset.h
 * @brief
 */

#ifndef LABO04_OFFSET_H
#define LABO04_OFFSET_H

class Offset {
    int x, y;
public:
    /**
     *
     * @param x
     * @param y
     */
    Offset(int x, int y);

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
};


#endif //LABO04_OFFSET_H
