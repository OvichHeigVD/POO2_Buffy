/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Utils.h
 * @brief
 */

#ifndef LABO04_UTILS_H
#define LABO04_UTILS_H

#include <random>

class Utils {
public:
    /**
     * Méthode permettant de générer un booléen en se basant sur la loi de
     * Bernoulli (p = 0.5). Cette méthode est utilisée pour savoir si un humain
     * doit se transformer en vampire ou être tué.
     * @return Vrai si tué, faux si transformé
     */
    static bool randomBool();

    /**
     * Méthode permettant de générer un nombre dans une borne définie
     * @param min - Le minimum
     * @param max - Le maximum
     * @return un nombre aléatoire
     */
    static int randomInt(int min, int max);

private:
    /**
     *
     * @return
     */
    static unsigned getSeed();

    static std::mt19937 eng;
};

#endif //LABO04_UTILS_H