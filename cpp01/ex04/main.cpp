#include <string>
#include <iostream>
#include <fstream>

void	ft_replace(std::string& str, std::string find, std::string replace)
{
	std::string	manage(str);
	std::size_t	offset = 0;
	std::size_t	i;

	while ((i = manage.find(find)) < manage.length())
	{
		manage = manage.substr(i + 1);
		str.erase(i + offset, find.length());
		str.insert(i + offset, replace);
		offset += i + replace.length() - find.length() + 1;
	}
}

int main(int argc, char** argv)
{
	std::fstream	file;
	std::string		line = "";

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments!" << std::endl;
		return (1);
	}
	std::string		filename = std::string(argv[1]);
	std::string		find = std::string(argv[2]);
	std::string		replace = std::string(argv[3]);
	file.open(filename.c_str());

	if (!file.is_open() || !file.good())
	{
		std::cout << "Could not open file!" << std::endl;
		file.close();
		return (2);
	}
	std::ofstream	ofile(filename.append(".replace").c_str());

	if (!ofile.is_open() || !ofile.good())
	{
		std::cout << "Could not open output file!" << std::endl;
		file.close();
		ofile.close();
		return (3);
	}

	while (std::getline(file, line))
	{
		ft_replace(line, find, replace);
		ofile << line << std::endl;
	}
	file.close();
}
