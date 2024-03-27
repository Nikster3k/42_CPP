#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal(void);
	AAnimal( const AAnimal& obj);
	AAnimal&	operator= (const AAnimal& obj);
	virtual ~AAnimal();

	const std::string&	getType( void ) const;
	virtual void		makeSound( void ) const;
};


#endif //!ANIMAL_HPP
