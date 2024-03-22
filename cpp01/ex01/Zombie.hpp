#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
	void	announce( void );
	void	setName( std::string name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif //!ZOMBIE_HPP
