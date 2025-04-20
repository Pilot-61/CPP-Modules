#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Myaaaaaaw (WrongCat)" << std::endl;
}
