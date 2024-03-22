#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat buro = Bureaucrat("Juergen", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << '\n';
		}
		
		Bureaucrat buro = Bureaucrat("Peter", 1);
		std::cout << buro << std::endl;

		try
		{
			buro.decrement();
			std::cout << buro << std::endl;
			buro.increment();
			std::cout << buro << std::endl;
			std::cout << "Increment decrement works!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << '\n';
		}
		

		try
		{
			buro.increment();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << '\n';
		}
	}

	std::cout << "\n=== Form Tests ===\n" << std::endl;

	Bureaucrat	ceo("Peter", 1);
	Bureaucrat	buro("Gregor", 22);
	AForm	document("Divorce Papers", 3, 1);

	std::cout << document << std::endl;

	buro.signForm(document);
	ceo.signForm(document);

	std::cout << document << std::endl;

	AForm generic("Generic Document" , 100, 5);

	std::cout << generic << std::endl;

	buro.signForm(generic);
	ceo.signForm(generic);

	std::cout << "=== FormTryCatches ===" << std::endl;
	try
	{
		AForm over("Over 9000", 9001, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm under("Over 9000", 9001, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm under("Over 9000", 1, 9001);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm under("Just a little", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm under("Just a little", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm under("Just a little", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm over("Just a little", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm over("Just a little", -2147483648, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
