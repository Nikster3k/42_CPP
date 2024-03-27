#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public AAnimal 
{
public:
	Cat( void );
	Cat( const Cat& other );
	Cat&	operator=( const Cat& other );
	~Cat();

	void	makeSound( void ) const;
};

#endif // CAT_HPP
