#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap( std::string name );
	~ScavTrap();

	void	attack( const std::string& a_sTarget);
	void	guardGate( void );
};


#endif //!SCAV_TRAP_HPP
