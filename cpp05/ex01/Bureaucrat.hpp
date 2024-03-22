#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int		grade;
public:
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& obj );
	Bureaucrat&	operator= ( const Bureaucrat& obj );
	~Bureaucrat();

	const std::string&		getName( void ) const;
	const int&	getGrade( void ) const;

	void	increment( void );
	void	decrement( void );
	void	signForm( Form& form );
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

std::ostream&	operator<<( std::ostream& os , const Bureaucrat& obj );

#endif //!BUREAUCRAT_HPP
