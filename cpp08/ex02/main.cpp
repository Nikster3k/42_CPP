#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <list>

int	subjMain(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int	main(void)
{
	MutantStack<std::string>	mstack;

	mstack.push("Hello");
	mstack.push("World");
	mstack.push("This iterator");
	mstack.push("is pretty kewl! no?");
	mstack.push("lllll7ll77711!11!");

	std::cout.setf(std::cout.left);
	std::cout << "operator* operator=" << std::endl;
	for (MutantStack<std::string>::iterator i = mstack.begin(); i != mstack.end(); ++i)
	{
		std::cout << std::setw(20) << *i << " | len: " << i->length() << std::endl;
		*i = "Change!";
	}

	for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "operator->" << std::endl;
	std::cout << mstack.begin()->length() << std::endl;
	
	std::cout << std::endl << "Subject main" << std::endl;
	subjMain();
	return (0);
}
