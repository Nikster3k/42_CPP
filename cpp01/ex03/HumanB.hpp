#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	HumanB( Weapon* weapon );
	~HumanB();
	void	attack( void );
	void	setWeapon(Weapon wep);
};

#endif //!HUMANB_HPP