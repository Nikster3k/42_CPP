#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called!" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog make woof!" << std::endl;
}
