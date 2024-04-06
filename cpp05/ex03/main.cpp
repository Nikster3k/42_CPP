#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	president("President", 1); //60

	{
		RobotomyRequestForm form("Nikolai");

		president.signForm(form);
		president.executeForm(form);
	}

	{
		ShrubberyCreationForm form("Nikolai");

		president.signForm(form);
		president.executeForm(form);
	}

	{
		PresidentialPardonForm form("Nikolai");

		president.signForm(form);
		president.executeForm(form);
	}

	Intern knecht = Intern();
	AForm*	tmp;

	tmp = knecht.makeForm("presidential pardon", "Fheid");
	president.signForm(*tmp);
	president.executeForm(*tmp);
	delete tmp;
}
