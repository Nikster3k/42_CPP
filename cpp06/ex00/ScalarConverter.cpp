#include "ScalarConverter.hpp"

static void	printChar(double val)
{
	char	c(static_cast<char>(val));
	std::cout << "char: ";
	if (val > std::numeric_limits<char>().max() || val < std::numeric_limits<char>().min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (!isprint(c) || c == 32)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << c << std::endl;
}

static void	printInt(double dval, int ival)
{
	std::cout << "int: ";
	if (dval > std::numeric_limits<int>().max()
		|| dval < std::numeric_limits<int>().min()
		|| ival != static_cast<int>(dval))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(dval) << std::endl;
}

static void	printFloat(float fval)
{
	std::cout << "float: ";
	if (fval - roundf(fval) == 0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << fval << "f" << std::endl;
}

static void	printDouble(double dval)
{
	std::cout << "double: ";
	std::cout << dval << std::endl;
}

static bool	checkValid(const std::string& a_input)
{
	size_t	f_pos;
	size_t i = 0;
	if (a_input.length() == 1)
		return (true);
	if (a_input.at(0) == '+' || a_input.at(0) == '-')
		i++;
	std::string sub = a_input.substr(i);
	if (sub == "inf" || sub == "inff" || sub == "nan" || sub == "nanf")
		return (true);
	for (; i < a_input.length(); i++)
	{
		if (!isdigit(a_input.at(i)) && a_input.at(i) != '.' && a_input.at(i) != 'f')
			return (false);
	}
	if (((f_pos = a_input.find('f')) != a_input.length() - 1 && f_pos != size_t(-1)) || f_pos < 2)
		return (false);
	if (a_input.find('.') > f_pos)
		return (false);
	return (true);
}

void	ScalarConverter::convert(const std::string& a_value)
{
	char	*end = NULL;
	std::cout << std::fixed;
	double dval = std::strtod(a_value.c_str(), &end);
	float fval = static_cast<float>(dval);
	int ival = std::atoi(a_value.c_str());
	long lval = std::strtol(a_value.c_str(), &end, 10);
	if (a_value.length() == 1 && !isdigit(a_value.at(0)))
		dval = lval = fval = ival = a_value.at(0);
	if (!checkValid(a_value))
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	if (a_value.find('.') < a_value.length())
	{
		if (a_value.find('f') < a_value.length())
			ival = dval = fval;
		else
			ival = fval = dval;
	}
	else if (ival != lval)
	{
		std::cout << "Not valid" << std::endl;
		return ;
	}
	printChar(dval);
	printInt(dval, ival);
	printFloat(fval);
	printDouble(dval);
}
