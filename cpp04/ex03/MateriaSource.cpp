#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < 4; i++)
		learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (obj.learned[i] != NULL)
			learned[i] = obj.learned[i]->clone();
		else
			learned[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator= (const MateriaSource& obj)
{
	if (this != &obj)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (obj.learned[i] != NULL)
			{
				delete	learned[i];
				learned[i] = obj.learned[i]->clone();
			}
			else
				learned[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		delete learned[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (learned[i] == NULL && m != NULL)
		{
			learned[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (learned[i] != NULL && learned[i]->getType() == type)
			return (learned[i]->clone());
	}
	std::cout << "Material <" << type << "> not learned." << std::endl;
	return (NULL);
}
