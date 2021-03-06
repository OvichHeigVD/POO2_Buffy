/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 2 juin 2021
 *
 * @file Utils.cpp
 * @brief Implémentation de la classe Utils
 */

#include "Utils.h"

#include <chrono>

std::mt19937 Utils::eng{Utils::getSeed()};

bool Utils::randomBool() {
    return std::bernoulli_distribution{0.5}(eng);
}

int Utils::randomInt(int min, int max) {
    return std::uniform_int_distribution<int>{min, max}(eng);
}

unsigned Utils::getSeed() {
    return std::chrono::system_clock::now().time_since_epoch().count();
}