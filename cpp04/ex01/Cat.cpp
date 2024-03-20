#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called!" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat make miau!" << std::endl;
}
