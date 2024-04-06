#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& a_cOther) 
{
	(void)a_cOther;
}

Intern&	Intern::operator= (const Intern& a_cOther) 
{
	(void) a_cOther;
	return (*this);
}

Intern::~Intern() {}

static	AForm*	newPresidential(const std::string& a_sTarget)
{
	return (new PresidentialPardonForm(a_sTarget));
}

static	AForm*	newRobotomy(const std::string& a_sTarget)
{
	return (new RobotomyRequestForm(a_sTarget));
}

static	AForm*	newShrubbery(const std::string& a_sTarget)
{
	return (new ShrubberyCreationForm(a_sTarget));
}

typedef AForm *(*FormConst)(const std::string&);

AForm*	Intern::makeForm(std::string a_sFormName, std::string a_sFormTarget)
{
	const std::string	formTypes[] = {"presidential pardon", "robotomy request", "shrubbery creation" };
	FormConst			forms[] = {&newPresidential, &newRobotomy, &newShrubbery};

	for (size_t i = 0; i < 3; i++)
	{
		if (a_sFormName == formTypes[i])
		{
			AForm* created = forms[i](a_sFormTarget);
			std::cout << "Intern created " << created->getName() << std::endl;
			return (created);
		}
	}
	std::cout << "Form <" << a_sFormName << "> does not exist!" << std::endl;
	return (NULL); 
}
