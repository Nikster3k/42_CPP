#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog constructor called!" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
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

void	Dog::setIdeas(const std::string& idea)
{
	brain->setIdeas(idea);
}

void	Dog::printBrain(void) const
{
	for (size_t i = 0; i < 5; i++)
		std::cout << brain->getIdea(i) << std::endl;
	std::cout << "... 95 more ..." << std::endl;
}
