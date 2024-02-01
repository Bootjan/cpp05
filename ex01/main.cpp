/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 12:21:28 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:09:43 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	edward("Edward", 5);
	Form		contract("Contract for new pipeline", 4, 2);
	std::cout << contract << std::endl;
	std::cout << edward << std::endl;
	edward.signForm(contract);
	edward.Promotion();
	contract.beSigned(edward);
	std::cout << contract << std::endl;
	try
	{
		contract.beSigned(edward);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
