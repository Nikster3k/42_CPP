#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( std::string name );
	~FragTrap();

	void	highFiveGuys( void );
};

#endif //!FRAG_TRAP_HPP
