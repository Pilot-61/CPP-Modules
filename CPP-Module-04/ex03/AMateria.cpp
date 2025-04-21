#include "AMateria.hpp"

AMateria::AMateria() : type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src) : type(src.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
    if (this != &rhs) {
        type = rhs.type;
    }
    std::cout << "AMateria assignment operator called" << std::endl;
    return *this;
}

const std::string &AMateria::getType() const {
    return type;
}

void AMateria::use() {
    std::cout << "Using AMateria of type: " << type << std::endl;
}

