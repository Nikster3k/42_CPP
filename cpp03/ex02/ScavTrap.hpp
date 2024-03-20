#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& obj);
	ScavTrap&	operator= (const ScavTrap& obj);
	~ScavTrap();

	void	attack( const std::string& a_sTarget);
	void	guardGate( void );
};


#endif //!SCAV_TRAP_HPP
