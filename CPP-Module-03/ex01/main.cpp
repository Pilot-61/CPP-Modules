#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

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
    scavtrap.takeDamage(200);
    scavtrap.guardGate();
    scavtrap.beRepaired(3);
    scavtrap.attack("target2");
    return 0;
}