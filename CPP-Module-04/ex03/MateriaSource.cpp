#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materiaCount(0) {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        materia[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src) : materiaCount(src.materiaCount) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (src.materia[i]) {
            materia[i] = src.materia[i]->clone();
        } else {
            materia[i] = NULL;
        }
    }
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < materiaCount; ++i) {
        delete materia[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < materiaCount; ++i) {
            delete materia[i];
        }
        materiaCount = rhs.materiaCount;
        for (int i = 0; i < 4; ++i) {
            if (rhs.materia[i]) {
                materia[i] = rhs.materia[i]->clone();
            } else {
                materia[i] = NULL;
            }
        }
    }
    std::cout << "MateriaSource assignment operator called" << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (materiaCount < 4 && m) {
        materia[materiaCount++] = m;
        std::cout << "Learned " << m->getType() << " materia" << std::endl;
    } else {
        std::cout << "MateriaSource is full or invalid materia" << std::endl;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < materiaCount; ++i) {
        if (materia[i]->getType() == type) {
            std::cout << "Created " << type << " materia" << std::endl;
            return materia[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found" << std::endl;
    return NULL;
}
