#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : m_name(name), m_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->m_weapon = &weapon;
}

void HumanB::attack() const
{
    std::cout << this->m_name << " attacks with his " << this->m_weapon->getType() << std::endl;
}

