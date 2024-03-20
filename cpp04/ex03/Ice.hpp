#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp" 
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice& obj );
	Ice&	operator= (const Ice& obj );
	~Ice();

	std::string const &	getType() const;
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif //!ICE_HPP
