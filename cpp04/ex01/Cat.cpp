#include "Cat.hpp"

Cat::Cat(void) : Animal()
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

void	Cat::setIdeas(const std::string& idea)
{
	brain->setIdeas(idea);
}

void	Cat::printBrain(void) const
{
	for (size_t i = 0; i < 5; i++)
		std::cout << brain->getIdea(i) << std::endl;
	std::cout << "... 95 more ..." << std::endl;
}
