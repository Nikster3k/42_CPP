#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter(void);
	~ScalarConverter();
public:
	static void	convert(const std::string& a_value);
};

#endif //!SCALARCONVERTER_H
