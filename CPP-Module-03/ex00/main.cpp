#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.takeDamage(2);
    claptrap.beRepaired(3);
    claptrap.attack("target2");
    return 0;
}