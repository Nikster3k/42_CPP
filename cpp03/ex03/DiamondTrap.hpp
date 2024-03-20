#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap& obj );
	DiamondTrap&	operator= ( const DiamondTrap& obj );
	~DiamondTrap();

	void    attack( const std::string& a_sTarget );
};

#endif //!DIAMOND_TRAP_HPP
