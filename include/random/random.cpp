#include <random>
#include <ctime>

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

int getRandomNumber(int min, int max) {
    std::uniform_int_distribution<> die{ min, max };
    return die(mersenne);
}