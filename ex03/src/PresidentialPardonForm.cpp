/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:32:52 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:40:01 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// #############################################################################
//			CON/DE STRUCTORS
// #############################################################################

PresidentialPardonForm::PresidentialPardonForm( const std::string& name )
	: AForm(name, 25, 5)
{
	std::cout	<< "'" << name
				<< "' was created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "'" << this->getName() << "' was ripped apart" << std::endl;
}


// #############################################################################
//			EXECUTE FUNCTIONS
// #############################################################################

void	pardon(const std::string& name)
{
	std::cout << name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor) const
{

	if (!AForm::isSigned())
		throw NotSignedException();
	else if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException("Bureaucrats");
	else
		pardon(executor.getName());
}
