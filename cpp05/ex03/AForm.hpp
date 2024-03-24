#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			exec_grade;
public:
	AForm( std::string name, int sign_grade, int exec_grade );
	AForm( const AForm& obj );
	virtual ~AForm();

	const std::string&	getName( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	bool				isSigned( void ) const;
	void				beSigned( const Bureaucrat& buro );
	virtual void		execute( Bureaucrat const & executor ) const = 0;
	void				checkExecuteRights( const Bureaucrat& executor ) const;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<< ( std::ostream& os, const AForm& form );

#endif //!FORM_HPP
