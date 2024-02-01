/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:30:43 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/17 20:57:28 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int		matchForm(const std::string& type)
{
	int	idx = 0;
	std::string	types[] = { "robotomy request", "presidential pardon", "shrubbery creation" };

	while (idx < 3 && types[idx] != type)
		idx++;
	return idx;
}

AForm*	Intern::makeForm(const std::string& type, const std::string& name)
{
	AForm*	ret = NULL;
	int		idx = matchForm(type);
	switch (idx)
	{
		case 0: ret = new RobotomyRequestForm(name); break;
		case 1: ret = new PresidentialPardonForm(name); break;
		case 2: ret = new ShrubberyCreationForm(name); break;
		default: std::cout << "Form of type '" << type << "' doesn't exist" << std::endl; break;
	}
	if (!ret)
		return NULL;
	std::cout << "Intern creates '" << name << "'" << std::endl;
	return ret;
}
