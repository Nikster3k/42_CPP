#ifndef GROUND_HPP
# define GROUND_HPP

# include "AMateria.hpp"
# define MAX_DROPPED 10

class Ground
{
private:
	static AMateria*	_ground[MAX_DROPPED];
	static int			_top;
	Ground( void );
	Ground( const Ground& other );
	Ground& operator= ( const Ground& other );
	~Ground();
public:
	static void addGround( AMateria* m );
	static void cleanGround( void );
};

#endif //!GROUND_HPP
