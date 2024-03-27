#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal 
{
private:
	Brain	*brain;
public:
	Dog( void );
	Dog( const Dog& other );
	Dog&	operator=( const Dog& other );
	~Dog();

	void	makeSound( void ) const;

	void	setIdeas( const std::string& idea );
	void	printBrain( void ) const;
};

#endif // DOG_HPP
