#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat constructor called!" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat make miau!" << std::endl;
}