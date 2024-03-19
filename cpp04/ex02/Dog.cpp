#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog constructor called!" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog make woof!" << std::endl;
}
