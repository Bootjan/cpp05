/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 22:51:25 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/18 15:47:10 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	john;
	try
	{
		john = new Bureaucrat("John", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat	edward("Edward", 1);
	std::cout << *john << std::endl;
	std::cout << edward << std::endl;
	edward.Promotion();
	edward.Demotion();
}
