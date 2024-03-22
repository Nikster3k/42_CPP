#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	ShrubberyCreationForm pres("Nikolai");
	Bureaucrat	president("President", 1);

	pres.beSigned(president);
	pres.execute(president);

}
