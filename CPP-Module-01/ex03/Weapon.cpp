#include "Weapon.hpp"

Weapon::Weapon() : type("default")
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string const &Weapon::getType()
{
    return (this->type);
}

