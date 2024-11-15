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
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecuteRights(executor);
	std::srand(std::time(NULL));

	std::cout << "BzzzzZzzzZZZZZz..." << std::endl;
	sleep(1);
	std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
	sleep(1);
	std::cout << "BzzzzZzzzZZZZZz..." << std::endl;
	sleep(1);

	int	random = std::rand();
	std::cout << _target << " has been " <<
		(random > RAND_MAX / 2 ? "successfully" : "unsuccessfully")
		<< " robotomized!" << std::endl;
}
