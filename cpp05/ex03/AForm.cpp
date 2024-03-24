#include "AForm.hpp"

AForm::AForm(std::string name, int sign_grade, int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	is_signed = false;
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw (AForm::GradeTooLowException());
	else if (this->sign_grade < 1 || this->exec_grade < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm& obj)
	: name(obj.name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{
	is_signed = obj.is_signed;
}

AForm::~AForm() {}

const std::string&	AForm::getName(void) const
{
	return (name);
}

int	AForm::getSignGrade(void) const
{
	return (sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (exec_grade);
}

bool	AForm::isSigned(void) const
{
	return (is_signed);
}

void	AForm::beSigned(const Bureaucrat& buro)
{
	if (buro.getGrade() > this->sign_grade)
		throw (AForm::GradeTooLowException());
	is_signed = true;
}

void	AForm::checkExecuteRights(const Bureaucrat& executor) const
{
	if (is_signed == false)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > exec_grade)
		throw (AForm::GradeTooLowException());
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("the grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("the grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("the form is not signed yet!");
}

std::ostream&	operator<< ( std::ostream& os, const AForm& AForm )
{
	os << "AForm: " << AForm.getName() << "; Sign grade: " << AForm.getSignGrade()
		<< "; Exec grade: " << AForm.getExecGrade() << "; Is signed: "
		<< (AForm.isSigned() ? "true" : "false") << ";";
	return (os);
}
