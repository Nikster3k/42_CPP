#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

std::string const & AMateria::getType() const
{
	return (type);
}

AMateria::~AMateria() {}

void	AMateria::use(ICharacter& target)
{
	std::cout << "You used a Materia on " << target.getName() << "? how..." << std::endl;
}
