#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called!" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other)
{
	type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat make miau!" << std::endl;
}
