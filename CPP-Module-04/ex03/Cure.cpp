#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    std::cout << "Cure assignment operator called" << std::endl;
    return *this;
}

AMateria *Cure::clone() const {
    std::cout << "Cure clone called" << std::endl;
    return new Cure(*this);
}

void Cure::use() {
    std::cout << "Cure use called" << std::endl;
    std::cout << "* heals an injured person *" << std::endl;
}
