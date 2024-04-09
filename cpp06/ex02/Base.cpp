#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base(void) {}

Base::~Base() {}

Base*	Base::generate(void)
{
	int	val = std::rand() % 3;
	if (val == 0)
		return (new A());
	else if (val == 1)
		return (new B());
	else if (val == 2)
		return (new C());
	return (NULL);
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class is of type C" << std::endl;
	else
		std::cout << "Not a derived class" << std::endl;
}

void	Base::identify(Base& p)
{
	try
	{
		A test = dynamic_cast<A&>(p);
		std::cout << "Class is of type A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B test = dynamic_cast<B&>(p);
		std::cout << "Class is of type B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C test = dynamic_cast<C&>(p);
		std::cout << "Class is of type C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
