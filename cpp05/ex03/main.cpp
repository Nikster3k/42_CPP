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
		RobotomyRequestForm pres("Nikolai");

		president.signForm(pres);
		president.executeForm(pres);
	}

	{
		ShrubberyCreationForm pres("Nikolai");

		president.signForm(pres);
		president.executeForm(pres);
	}

	{
		PresidentialPardonForm pres("Nikolai");

		president.signForm(pres);
		president.executeForm(pres);
	}

	Intern knecht = Intern();
	AForm*	tmp;

	tmp = knecht.makeForm("presisdsfdential pardon", "Fheid");
	delete tmp;
}
