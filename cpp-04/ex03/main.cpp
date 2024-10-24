#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); //  * shoots an ice bolt at bob *
    me->use(1, *bob); //  * heals bob's wounds *

    delete bob;
    delete me;
    delete src;


    std::cout << "\n=======================\n";

    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Cure());
    src2->learnMateria(new Cure()); 

    ICharacter* alice = new Character("alice");
    AMateria* tmp2;
    tmp2 = src2->createMateria("cure");
    alice->equip(tmp2);
    tmp2 = src2->createMateria("cure");
    alice->equip(tmp2);
    tmp2 = src2->createMateria("ice"); // Materia non learned
    alice->equip(tmp2); // Should not equip

    ICharacter* charlie = new Character("charlie");
    alice->use(0, *charlie); // * heals charlie's wounds *
    alice->use(1, *charlie); // * heals charlie's wounds *
    alice->use(2, *charlie); // Nothing happens

    std::cout << "\n=======================\n";
    Character original("original");
    original.equip(new Ice());
    original.equip(new Cure());

    Character copy = original; 
    copy.use(0, *charlie); // * shoots an ice bolt at charlie *
    copy.use(1, *charlie); // * heals charlie's wounds *

    std::cout << "\n=======================\n";
    Character assigned("assigned");
    assigned = original; 
    assigned.use(0, *charlie); // * shoots an ice bolt at charlie *
    assigned.use(1, *charlie); // * heals charlie's wounds *

    delete alice;
    delete charlie;
    delete src2;

    return 0;
}
