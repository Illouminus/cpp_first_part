#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* knownMaterias[4];
    int count;

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);

    MateriaSource &operator=(const MateriaSource &src);

    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};
