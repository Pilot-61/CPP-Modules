#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *(this->brain) = *(src.brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain();
        if (rhs.brain)
            *(this->brain) = *(rhs.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Haw Haw Haw(kaynb7 z3ma)" << std::endl;
}
