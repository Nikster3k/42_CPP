#include "Character.hpp"

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	this->name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character&	Character::operator= (const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = other.inventory[i]->clone();
			}
			else
				inventory[i] = NULL;
		}
		
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		delete inventory[i];
}

std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	inventory[idx] = NULL;
	//leaks here have to store saved somewhere??!?!
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
