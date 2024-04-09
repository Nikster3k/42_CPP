#ifndef BASE_H
# define BASE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

// class A;
// class B;
// class C;

class Base
{
public:
	Base(void);
	virtual ~Base();

	Base*	generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif //!BASE_H
