#include "Character.hpp"

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (size_t i = 0; i < MAX_DROPPED; i++)
		dropped[i] = NULL;
	droptop = 0;	
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
	for (size_t i = 0; i < MAX_DROPPED; i++)
	{
		if (i <= other.droptop && other.dropped[i] != NULL)
			dropped[i] = other.dropped[i]->clone();
		else
			dropped[i] = NULL;
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
		for (size_t i = 0; i < MAX_DROPPED; i++)
		{
			if (i <= other.droptop && other.dropped[i] != NULL)
			{
				delete dropped[i];
				dropped[i] = other.dropped[i]->clone();
			}
			else
				dropped[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		delete inventory[i];
	for (size_t i = 0; i < MAX_DROPPED; i++)
		delete dropped[i];
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

void	Character::addDropped(AMateria* m)
{
	if (m == NULL)
		return ;
	if (droptop >= MAX_DROPPED)
		droptop = 0;
	if (dropped[droptop] != NULL)
		delete dropped[droptop];
	dropped[droptop++] = m;
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	addDropped(inventory[idx]);
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
