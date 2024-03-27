#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat constructor called!" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called!" << std::endl;
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
