#include <iostream>
#include "Zombie.hpp"
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "--- Stack Allocation ---" << std::endl;
    randomChump("Stacky");
    std::cout << "\n--- Heap Allocation ---" << std::endl;
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;
    return 0;
}