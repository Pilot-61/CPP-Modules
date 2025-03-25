#include <iostream>
#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name) {
    if (N <= 0) {
        std::cerr << "Invalid horde size. Must be positive." << std::endl;
        return 0;
    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; ++i) {
        std::stringstream ss;
        ss << i + 1;
        std::string zombieName = name + "_" + ss.str();
        horde[i].setName(zombieName);
    }
    return horde;
}