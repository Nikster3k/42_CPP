#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& obj) : AMateria(obj.getType()) {}

Cure&	Cure::operator= (const Cure& obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Cure::~Cure() {}

std::string const & Cure::getType() const
{
	return (AMateria::getType());
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
