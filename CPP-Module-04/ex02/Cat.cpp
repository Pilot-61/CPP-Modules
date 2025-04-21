#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    *(this->brain) = *(src.brain);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat assignment operator called" << std::endl;
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

void Cat::makeSound() const
{
    std::cout << "Myaaaaaaw" << std::endl;
}
