/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 12:21:28 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:38:04 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	Bureaucrat	edward("Edward", 1);
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rrf)
		return 1;
	std::cout << *rrf << std::endl;
	edward.executeForm(*rrf);
	edward.signForm(*rrf);
	edward.executeForm(*rrf);
	delete rrf;
	return 0;
}
