#include <iostream>
#include <string>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Original adress: " << &str << std::endl;
	std::cout << "Pointer adress: " << stringPTR << std::endl;
	std::cout << "Reference adress: " << &stringREF << std::endl;

	std::cout << "Original value: " << str << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl;
}
