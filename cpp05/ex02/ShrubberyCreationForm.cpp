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

std::string tree[15] = {"baum spitze",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"mitte",
						"baum ende"
						};

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExecuteRights(executor);

	std::ofstream shrubfile((_target + "_shrubbery").c_str());

	if (!shrubfile.is_open() || !shrubfile.good())
	{
		std::cout << "Could not open " << _target + "_shrubbery !" << std::endl;
		return ;
	}

	for (size_t i = 0; i < 15; i++)
		shrubfile << tree[i] << std::endl;
	shrubfile.close();
}
