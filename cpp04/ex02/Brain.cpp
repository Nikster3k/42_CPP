#include "Brain.hpp"

Brain::Brain( void ) 
{
	std::cout << "Brain constructor called!" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "random idea...";
}

Brain::Brain( const Brain& obj)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
}

Brain&	Brain::operator= (const Brain& obj)
{
	std::cout << "Brain copy assignment operator called!" << std::endl;
	if (this != &obj)
	{
		for (size_t i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() 
{
	std::cout << "Brain destructor called!" << std::endl;
}

const std::string&	Brain::getIdea(unsigned int idx) const
{
	if (idx >= 100)
		idx = 99;
	return (ideas[idx]);
}

void	Brain::setIdeas(const std::string& idea)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = idea;
}
