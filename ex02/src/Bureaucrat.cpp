/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 22:49:56 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/18 16:33:34 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// #############################################################################
//			CON/DE STRUCTORS
// #############################################################################

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " is born" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " has left this world" << std::endl;
}

// #############################################################################
//			OVERLOAD OPERATORS
// #############################################################################

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
	o << bureaucrat.getName();
	o << ", bureaucrat grade ";
	o << bureaucrat.getGrade();
	return o;
}


// #############################################################################
//			GETTERS
// #############################################################################

const std::string&	Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}


// #############################################################################
//			PRO/DE MOTION
// #############################################################################

void	Bureaucrat::Promotion( void )
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << this->getName() << " was promoted to grade " << _grade << std::endl;
}

void	Bureaucrat::Demotion( void )
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << this->getName() << " was demoted to grade " << _grade << std::endl;
}

void	Bureaucrat::signForm( AForm& form ) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< _name << " signed '"
					<< form.getName() << "'" << std::endl;
	}
	catch(const AForm::ExecuteException &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout	<< _name << " executed '"
					<< form.getName() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
