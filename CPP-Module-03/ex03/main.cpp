#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.takeDamage(2);
    claptrap.beRepaired(3);
    claptrap.attack("target2");

    ScavTrap scavtrap("SCTP");
    scavtrap.attack("target1");
    scavtrap.takeDamage(5);
    scavtrap.takeDamage(2);
    scavtrap.guardGate();
    scavtrap.beRepaired(3);
    scavtrap.attack("target2");

    FragTrap fragtrap("FRTP");
    fragtrap.attack("target1");
    fragtrap.takeDamage(5);
    fragtrap.takeDamage(2);
    fragtrap.highFivesGuys();
    fragtrap.beRepaired(3);
    fragtrap.attack("target2");

    DiamondTrap diamondTrap("DMT");
    diamondTrap.attack("target1");
    diamondTrap.takeDamage(5);
    diamondTrap.takeDamage(200);
    diamondTrap.highFivesGuys();
    diamondTrap.beRepaired(3);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.attack("target2");

    return 0;
}