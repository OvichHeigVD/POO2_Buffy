//
// Created by stefa on 22.05.2021.
//

#ifndef LABO04_DISPLAY_H
#define LABO04_DISPLAY_H
#include <cstddef>
#include "../Field.h"

class Humanoid;
class Display : public Field{
private:
    bool isRunning() const;
    void stop();
    int nextTurn() override;
    void clear();
    void drawLine() const;
public:
    Display(int width, int height, int numberOfHumans, int numberOfVampires);
    ~Display() override;
    void run();
private:
    Humanoid*** screen;
    bool running;
};


#endif //LABO04_DISPLAY_H
