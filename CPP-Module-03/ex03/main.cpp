#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap diamondTrap("DMT");
    diamondTrap.attack("target1");
    diamondTrap.takeDamage(5);
    diamondTrap.takeDamage(2);
    diamondTrap.highFivesGuys();
    diamondTrap.beRepaired(3);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.attack("target2");

    return 0;
}