#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called!" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
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
