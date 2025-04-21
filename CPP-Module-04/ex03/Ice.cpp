#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    std::cout << "Ice assignment operator called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const {
    std::cout << "Ice clone called" << std::endl;
    return new Ice(*this);
}

void Ice::use() {
    std::cout << "Ice use called" << std::endl;
    std::cout << "* shoots an ice bolt *" << std::endl;
}