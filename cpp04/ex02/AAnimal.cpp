#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	type = obj.type;
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

const std::string&	AAnimal::getType(void) const
{
	return (type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Generic animal sounds..." << std::endl;
}
