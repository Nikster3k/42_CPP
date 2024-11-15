#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria( void );
	AMateria( std::string const & type);
	AMateria( const AMateria& obj );
	virtual ~AMateria();

	std::string const &	getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

};

#endif //!AMATERIA_HPP
