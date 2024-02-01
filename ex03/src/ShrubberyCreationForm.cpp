/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:23:22 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:39:55 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// #############################################################################
//			CON/DE STRUCTORS
// #############################################################################

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& name )
	: AForm(name, 145, 137)
{
	std::cout	<< "'" << name
				<< "' was created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "'" << this->getName() << "' was ripped apart" << std::endl;
}


// #############################################################################
//			EXECUTE FUNCTIONS
// #############################################################################

void	treeToFile(const std::string& name)
{
	std::string		filename = name;
	std::ofstream	outfile;
	filename += "_shrubbery";
	outfile.open(filename, std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
		return ;
	outfile << TREE;
	outfile.close();
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor) const
{
	if (!AForm::isSigned())
		throw NotSignedException();
	else if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException("Bureaucrats");
	else
		treeToFile(executor.getName());
}
