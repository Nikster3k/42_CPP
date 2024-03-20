#include "Brain.hpp"
#include <iostream>
Brain::Brain( void ) {}

Brain::Brain( const Brain& obj)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
}

Brain&	Brain::operator= (const Brain& obj)
{
	if (this != &obj)
	{
		for (size_t i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {}
