#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materia[4];
    int materiaCount;
public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &rhs);

    void learnMateria(AMateria *m);
    AMateria *createMateria(const std::string &type);
};
#endif