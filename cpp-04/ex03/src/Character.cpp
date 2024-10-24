#include "Character.hpp"
#include <iostream>



Character::Character() : name("default"), equipped(0)
{
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character " << name << " constructed.\n";
}


Character::Character(std::string const &name) : name(name), equipped(0)
{
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character " << name << " constructed.\n";
};


Character::Character(const Character &src) : name(src.name), equipped(src.equipped)
{
    for(int i = 0; i < 4; i++)
    {
        if(src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    // std::cout << "Character copied.\n";
}


Character &Character::operator=(const Character &src)
{
    if(this != &src)
    {
        name = src.name;
        equipped = src.equipped;

        for(int i = 0; i < 4; i++)
        {
            if(inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
            if(src.inventory[i])
                inventory[i] = src.inventory[i]->clone();
        }
        // std::cout << "Character assigned.\n";
    }
    return *this;
}


Character::~Character()
{
    for(int i = 0; i < 4; i++)
        if(inventory[i])
            delete inventory[i];
    // std::cout << "Character destructed.\n";
}


std::string const & Character::getName() const
{
    return this->name;
}



void Character::equip(AMateria* m)
{
    if(!m)
        return;
    for(int i = 0; i < 4; i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            // std::cout << name << " equipped " << m->getType() << " in slot " << i << ".\n";
            break;
        }
    }
}



void Character::unequip(int idx)
{
    if(idx < 0 || idx >=4 || !inventory[idx])
        return;
    // std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << ".\n";
    inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >=4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}


void Character::printInventory() const

{
    std::cout << name << "'s Inventory:\n";
    for(int i = 0; i < 4; i++)
    {
        std::cout << "Slot " << i << ": ";
        if(inventory[i])
            std::cout << inventory[i]->getType() << "\n";
        else
            std::cout << "Empty\n";
    }
}