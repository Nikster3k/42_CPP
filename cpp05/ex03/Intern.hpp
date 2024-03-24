#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern( void );
	~Intern();

	AForm*	makeForm( std::string a_sFormName, std::string a_sFormTarget );
};

#endif //!INTERN_HPP
