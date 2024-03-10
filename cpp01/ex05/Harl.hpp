#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum	level
{
	NONE,
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Harl( void );
	~Harl();
	void	complain( std::string level );
};

#endif //!HARL_HPP