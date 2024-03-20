#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	learned[4];
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource& obj );
	MateriaSource&	operator= ( const MateriaSource& obj );
	~MateriaSource();

	void learnMateria( AMateria* m );
	AMateria* createMateria(std::string const & type);
};

#endif //!MATERIASOURCE_HPP
