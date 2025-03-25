#include <iostream>
#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    Zombie* zombieH = zombieHorde(hordeSize, "Walker");
    for (int i = 0; i < hordeSize; ++i) {
        zombieH[i].announce();
    }
    delete[] zombieH;

    return 0;
}