#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed." << std::endl;
}


void FragTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    if (this->hitPoints > 0)
    {
        std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " is out of hit points!" << std::endl;
    }
}