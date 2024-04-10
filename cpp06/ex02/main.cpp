#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	Base basis = Base();
	Base*	rand;

	char *wow = NULL;

	rand = basis.generate();

	basis.identify((Base*)wow);
	basis.identify(rand);
	basis.identify(*rand);

	delete rand;
	return (0);
}
