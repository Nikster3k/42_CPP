#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

}
