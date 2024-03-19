#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria
{
protected:
	std::string	type;
public:
	AMateria( std::string const & type);
	//maybe copy constructor
	//and copy assign? operator
	virtual ~AMateria();

	std::string const &	getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

};

#endif //!AMATERIA_HPP
