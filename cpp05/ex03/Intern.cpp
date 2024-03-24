#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string a_sFormName, std::string a_sFormTarget)
{
	const std::string	formTypes[] = {"presidential pardon", "robotomy request", "shrubbery creation" };
	int					idx = -1;
	for (size_t i = 0; i < 3; i++)
	{
		if (a_sFormName == formTypes[i])
			idx = i;
	}
	switch (idx)
	{
	case 0:
		return (new PresidentialPardonForm(a_sFormTarget));
	case 1:
		return (new RobotomyRequestForm(a_sFormTarget));
	case 2:
		return (new ShrubberyCreationForm(a_sFormTarget));
	default:
		std::cout << "This form does not exist!" << std::endl;
		break;
	}
	return (NULL);
}
