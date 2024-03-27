#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain( void );
	Brain( const Brain& obj);
	Brain&	operator= (const Brain& obj);
	~Brain();

	const std::string&	getIdea( unsigned int idx ) const;
	void				setIdeas( const std::string& idea );
};

#endif //!BRAIN_HPP
