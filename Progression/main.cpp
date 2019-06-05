#include <iostream>
#include "Progression.h"
int main() {
    std::cout << "Arithmetic Progression: " << std::endl;

    for (auto i: ArithProgression(10))
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i: ArithProgression(1, 10))
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i: ArithProgression(1, 10, 2))
        std::cout << i << " ";

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Geometric Progression: " << std::endl;

    for (auto i: GeoProgression(20))
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i: GeoProgression(2, 30))
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i: GeoProgression(5, 105, 3))
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Fibonacci Progression: " << std::endl;

    for (auto i: FibonaProgression(100))
        std::cout << i << " ";
    std::cout << std::endl;

}