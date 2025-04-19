#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << this->name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > 0) {
        if (amount >= this->hitPoints) {
            this->hitPoints = 0;
        } else {
            this->hitPoints -= amount;
        }
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage. Hit points: " << this->hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        if (this->hitPoints > UINT_MAX - amount) {
            this->hitPoints = UINT_MAX;
        } else {
            this->hitPoints += amount;
        }
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " points. Hit points: " << this->hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}
