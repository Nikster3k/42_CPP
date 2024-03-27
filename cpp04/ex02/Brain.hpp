#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
public:
	Brain( void );
	Brain( const Brain& obj);
	Brain&	operator= (const Brain& obj);
	~Brain();

	std::string	ideas[100];
};

#endif //!BRAIN_HPP
