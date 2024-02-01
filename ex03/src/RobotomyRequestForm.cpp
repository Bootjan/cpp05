/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:08:52 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:39:58 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// #############################################################################
//			CON/DE STRUCTORS
// #############################################################################

RobotomyRequestForm::RobotomyRequestForm( const std::string& name )
	: AForm(name, 72, 45)
{
	std::cout	<< "'" << name
				<< "' was created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "'" << this->getName() << "' was ripped apart" << std::endl;
}


// #############################################################################
//			EXECUTE FUNCTIONS
// #############################################################################

void	doRobotomy( const std::string& name)
{
	std::cout << "BBBbbbzzzzzzttttt......" << std::endl;
	srand((unsigned)time(NULL));
	int	prob = rand() % 2;
	if (prob == 0)
		std::cout	<< "Robotomy on " << name
					<< " was succesfull" << std::endl;
	else
		std::cout	<< "Robotomy on " << name
					<< " failed succesfully" << std::endl;
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor) const
{
	if (!AForm::isSigned())
		throw NotSignedException();
	else if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException("Bureaucrats");
	else
		doRobotomy(executor.getName());
}
