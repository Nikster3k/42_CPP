#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ) : name(obj.name)
{
	grade = obj.grade;
}

Bureaucrat&	Bureaucrat::operator= ( const Bureaucrat& obj )
{
	if (this != &obj)
	{
		grade = obj.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName(void) const
{
	return (name);
}

const int&	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::increment( void )
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--grade;
}

void	Bureaucrat::decrement( void )
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		++grade;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.getName()
			<< " becuase " << e.what() << std::endl;
	}
	
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the grade is too low!");
}

std::ostream&	operator<<(std::ostream& os , const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
