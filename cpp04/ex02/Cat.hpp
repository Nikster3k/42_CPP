#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal 
{
private:
	Brain	*brain;
public:
	Cat( void );
	Cat( const Cat& other );
	Cat&	operator=( const Cat& other );
	~Cat();

	void	makeSound( void ) const;

	void	setIdeas( const std::string& idea );
	void	printBrain( void ) const;
};

#endif // CAT_HPP
