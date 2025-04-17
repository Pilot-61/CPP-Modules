#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is out of hit points!" << std::endl;
    }
}
