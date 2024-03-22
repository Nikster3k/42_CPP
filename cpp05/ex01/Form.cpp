#include "Form.hpp"

Form::Form(std::string name, int sign_grade, int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	is_signed = false;
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw (Form::GradeTooLowException());
	else if (this->sign_grade < 1 || this->exec_grade < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form& obj)
	: name(obj.name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{
	is_signed = obj.is_signed;
}

Form::~Form() {}

const std::string&	Form::getName(void) const
{
	return (name);
}

int	Form::getSignGrade(void) const
{
	return (sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (exec_grade);
}

bool	Form::isSigned(void) const
{
	return (is_signed);
}

void	Form::beSigned(const Bureaucrat& buro)
{
	if (buro.getGrade() > this->sign_grade)
		throw (Form::GradeTooLowException());
	is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low!");
}

std::ostream&	operator<< ( std::ostream& os, const Form& form )
{
	os << "Form: " << form.getName() << "; Sign grade: " << form.getSignGrade()
		<< "; Exec grade: " << form.getExecGrade() << "; Is signed: "
		<< (form.isSigned() ? "true" : "false") << ";";
	return (os);
}
