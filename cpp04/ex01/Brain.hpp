#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

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
