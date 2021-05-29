//
// Created by stefa on 25.05.2021.
//

#ifndef LABO04_UTILS_H
#define LABO04_UTILS_H
#include <random>

class Utils {
public:
    static bool randomBool();
    static int randomInt(int min, int max);
private:
    static unsigned getSeed();
    static std::mt19937 eng;
};


#endif //LABO04_UTILS_H
