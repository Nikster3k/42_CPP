#include <iostream>
#include <string>

int	main(int argc, char ** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) 
		{
			std::string str = std::string(argv[i]);
			for (unsigned long a = 0; a < str.length(); a++)
				str[a] = std::toupper(str[a]);
			std::cout << str << (i == argc - 1 ? "\n" : " ");
		}
	}
	return (0);
}
