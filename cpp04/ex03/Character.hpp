#ifndef CHARACTER_H
# define CHARACTER_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
public:
	Character( std::string name );
	Character( const Character& other);
	Character&	operator= ( const Character& other );
	~Character();

	std::string const & getName() const;
	void	equip( AMateria* m );
	void	unequip( int idx );
	void	use( int idx, ICharacter& target);
};

#endif //!CHARACTER_H
