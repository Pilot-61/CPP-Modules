#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : m_name("") {}

Zombie::Zombie(const std::string& name) : m_name(name) {}

Zombie::~Zombie() {
    if (!m_name.empty()) {
        std::cout << "Zombie " << m_name << " has been eliminated!" << std::endl;
    }
}

void Zombie::announce() const {
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
    m_name = name;
}