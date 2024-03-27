#include "Ground.hpp"

AMateria* Ground::_ground[MAX_DROPPED];
int	Ground::_top = 0;

Ground::~Ground()
{
	std::cout << "Deconstructor?" << std::endl;
	for (size_t i = 0; i < MAX_DROPPED; i++)
		delete _ground[i];
}

void	Ground::cleanGround(void)
{
	for (size_t i = 0; i < MAX_DROPPED; i++)
	{
		delete _ground[i];
		_ground[i] = NULL;
	}
}

void	Ground::addGround(AMateria* m)
{
	if (m == NULL)
		return ;
	if (_top >= MAX_DROPPED)
		_top = 0;
	if (_ground[_top] != NULL)
		delete _ground[_top];
	_ground[_top++] = m;
}
