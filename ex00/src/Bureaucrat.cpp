/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:49:56 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/16 23:08:55 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	try
	{
		if (grade < 1)
			throw &Bureaucrat::GradeTooLowException;
		if (grade > 150)
			throw &Bureaucrat::GradeTooHighException;
		_grade = grade;
		std::cout << "Bureaucrat " << _name << " is born" << std::endl;
	}
	catch(t_func ExceptionFunc)
	{
		(this->*ExceptionFunc)();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " has left this world" << std::endl;
}

void	Bureaucrat::GradeTooHighException( void ) const
{
	std::cout << "Given grade is too high!" << std::endl;
}

void	Bureaucrat::GradeTooLowException( void ) const
{
	std::cout << "Given grade is too low!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
	o << bureaucrat.getName();
	o << ", bureaucrat grade ";
	o << bureaucrat.getGrade();
	return o;
}

const std::string&	Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}
