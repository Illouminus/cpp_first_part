#include "Brain.hpp"
#include <iostream>



Brain::Brain()
{
    std::cout << "Brain constructed.\n";
}

Brain::Brain(const Brain &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copied.\n";
}

Brain::~Brain()
{
    std::cout << "Brain destructed.\n";
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brain assigned.\n";
    return *this;
}


void Brain::setIdea(const std::string idea, int index)
{
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}