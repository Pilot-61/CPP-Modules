#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
protected:
    std::string type;
public:
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &src);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &rhs);

    const std::string &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0; // Pure virtual function
    virtual void use() = 0; // Pure virtual function
};

#endif