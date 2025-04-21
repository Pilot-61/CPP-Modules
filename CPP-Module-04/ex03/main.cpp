#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
    // Create a MateriaSource
    IMateriaSource *src = new MateriaSource();

    // Create some Materia
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    // Learn the Materia
    src->learnMateria(ice);
    src->learnMateria(cure);

    // Create a Character
    ICharacter *me = new Character("me");

    // Equip some Materia
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Use the Materia
    me->use(0, *me);
    me->use(1, *me);

    // Clean up
    delete me;
    delete src;

    return 0;
}