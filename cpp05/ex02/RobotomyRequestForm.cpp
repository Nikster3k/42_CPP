#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
	_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
#include <cstdlib>
#include <ctime>
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecuteRights(executor);
	int	random = std::rand();
	std::cout << _target << " has been " <<
		(random > RAND_MAX / 2 ? "successfully" : "unsuccessfully")
		<< " robotomized!" << std::endl;
}
