#include <iostream>
#include "Zombie.hpp"

int main() {
    int N = 2;
    Zombie* zombieH = zombieHorde(N, "Walker");
    if (!zombieH)
        return 1;
    for (int i = 0; i < N; ++i)
        zombieH[i].announce();
    delete[] zombieH;
    return 0;
}