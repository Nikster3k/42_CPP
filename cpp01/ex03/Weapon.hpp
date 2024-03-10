#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon( std::string a_sType );
	~Weapon();
	std::string&	getType( void );
	void			setType( std::string a_sNewType );
};

#endif //!WEAPON_HPP