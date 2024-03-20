#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp" 
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure& obj );
	Cure&	operator= (const Cure& obj );
	~Cure();

	std::string const &	getType() const;
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif //!CURE_HPP
