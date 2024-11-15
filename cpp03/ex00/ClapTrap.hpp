#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
public:
	ClapTrap( void );
	ClapTrap( std::string a_sName );
	ClapTrap( const ClapTrap& obj);
	ClapTrap& operator= (const ClapTrap& obj);
	~ClapTrap();

	void	attack( const std::string& a_sTarget);
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif //!CLAP_TRAP_HPP
