#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& obj) : AMateria(obj.getType()) {}

Ice&	Ice::operator= (const Ice& obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Ice::~Ice() {}

std::string const & Ice::getType() const
{
	return (AMateria::getType());
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
