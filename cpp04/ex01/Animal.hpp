#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal( const Animal& obj);
	Animal&	operator= (const Animal& obj);
	virtual ~Animal();

	const std::string&	getType( void ) const;
	virtual void		makeSound( void ) const;
};


#endif //!ANIMAL_HPP
