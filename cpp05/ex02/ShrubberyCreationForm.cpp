#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	const std::string tree[15] = {"               ,@@@@@@@,",
						"       ,,,.   ,@@@@@@/@@,  .oo8888o.",
						"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o",
						"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'",
						"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'",
						"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'",
						"   `&%\\ ` /%&'    |.|        \\ '|8'",
						"       |o|        | |         | |",
						"       |.|        | |         | |",
						"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"};

	checkExecuteRights(executor);
	std::string filename(_target + "_shrubbery");
	std::ofstream shrubfile(filename.c_str());

	if (!shrubfile.is_open() || !shrubfile.good())
	{
		std::cout << "Could not open " << filename << "!" << std::endl;
		return ;
	}
	std::srand(std::time(NULL));
	int	amount = std::rand() % 10 + 1;
	for (int i = 0; i < amount; i++)
	{	
		for (size_t i = 0; i < 15; i++)
			shrubfile << tree[i] << std::endl;
	}
	shrubfile.close();
	std::cout << "Created " << filename << " and "
		<< amount << " trees!" << std::endl;
}
