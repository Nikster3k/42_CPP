#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat buro = Bureaucrat("Juergen", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	Bureaucrat a = Bureaucrat("Peter", 1);
	std::cout << a << std::endl;

	try
	{
		a.decrement();
		std::cout << a << std::endl;
		a.increment();
		std::cout << a << std::endl;
		std::cout << "Increment decrement works!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	

	try
	{
		a.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
}
