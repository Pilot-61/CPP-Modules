#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : 
    ClapTrap("Default_clap_name"), 
    ScavTrap("Default"),
    FragTrap("Default"),
    name("Default")
{
    this->hitPoints = 100;      // 100 from FragTrap
    this->energyPoints = 50; // 50 from ScavTrap
    this->attackDamage = 30; // 30 from FragTrap
    std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
    ClapTrap(name + "_clap_name"), 
    ScavTrap(name),
    FragTrap(name),
    name(name)
{
    this->hitPoints = 100;      // 100 from FragTrap
    this->energyPoints = 50; // 50 from ScavTrap
    this->attackDamage = 30; // 30 from FragTrap
    std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
    ClapTrap(other), 
    ScavTrap(other), 
    FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap " << this->name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}