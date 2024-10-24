#include "MateriaSource.hpp"



MateriaSource::MateriaSource() : count(0)
{
    for(int i = 0; i < 4; i++)
        knownMaterias[i] = NULL;
    // std::cout << "MateriaSource constructed.\n";
}


MateriaSource::MateriaSource(const MateriaSource &src) : count(src.count)
{
    for(int i = 0; i < 4; i++)
    {
        if(src.knownMaterias[i])
            knownMaterias[i] = src.knownMaterias[i]->clone();
        else
            knownMaterias[i] = NULL;
    }
    // std::cout << "MateriaSource copied.\n";
}


MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if(this != &src)
    {
        // Очистка текущих Materia
        for(int i = 0; i < 4; i++)
        {
            if(knownMaterias[i])
            {
                delete knownMaterias[i];
                knownMaterias[i] = NULL;
            }
        }

        count = src.count;
        for(int i = 0; i < 4; i++)
        {
            if(src.knownMaterias[i])
                knownMaterias[i] = src.knownMaterias[i]->clone();
            else
                knownMaterias[i] = NULL;
        }
        // std::cout << "MateriaSource assigned.\n";
    }
    return *this;
}


MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        if(knownMaterias[i])
            delete knownMaterias[i];
    // std::cout << "MateriaSource destructed.\n";
}


void MateriaSource::learnMateria(AMateria* m)
{
    if(m && count < 4)
    {
        knownMaterias[count] = m->clone();
        count++;
        // std::cout << "Materia " << m->getType() << " learned.\n";
    }
    // else
        // std::cout << "MateriaSource cannot learn more Materias or received NULL.\n";
}



AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < count; i++)
    {
        if(knownMaterias[i]->getType() == type)
        {
            // std::cout << "Materia " << type << " created.\n";
            return knownMaterias[i]->clone();
        }
    }
    // std::cout << "Materia " << type << " not found.\n";
    return NULL;
}