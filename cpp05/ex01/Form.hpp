#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			exec_grade;
public:
	Form( std::string name, int sign_grade, int exec_grade );
	Form( const Form& obj );
	~Form();

	const std::string&	getName( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	bool				isSigned( void ) const;
	void				beSigned( const Bureaucrat& buro );

	class GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<< ( std::ostream& os, const Form& form );

#endif //!FORM_HPP
