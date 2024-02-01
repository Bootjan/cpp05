/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 12:21:28 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:34:24 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	edward("Edward", 73);
	Bureaucrat	john("John", 45);
	ShrubberyCreationForm		contract("Contract for new pipeline");
	std::cout << std::endl;
	std::cout << contract << std::endl;
	std::cout << std::endl;
	std::cout << edward << std::endl;
	std::cout << std::endl;
	edward.signForm(contract);
	std::cout << std::endl;
	edward.Promotion();
	std::cout << std::endl;
	john.executeForm(contract);
	std::cout << std::endl;
	edward.signForm(contract);
	std::cout << std::endl;
	std::cout << contract << std::endl;
	std::cout << std::endl;
	edward.signForm(contract);
	std::cout << std::endl;
	std::cout << std::endl;
	edward.executeForm(contract);
	std::cout << std::endl;
	john.executeForm(contract);
	std::cout << std::endl;
	return 0;
}
