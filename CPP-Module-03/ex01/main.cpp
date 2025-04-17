#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ScavTrap scavtrap("SCTP");
    scavtrap.attack("target1");
    scavtrap.takeDamage(5);
    scavtrap.takeDamage(2);
    scavtrap.guardGate();
    scavtrap.beRepaired(3);
    scavtrap.attack("target2");
    return 0;
}