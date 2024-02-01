/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 12:19:07 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:05:23 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// #############################################################################
//			CON/DE STRUCTORS
// #############################################################################

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name)
	, _signGrade(signGrade)
	, _executeGrade(executeGrade)
{
	if (signGrade > 150)
		throw GradeTooLowException("Sign");
	if (signGrade < 1)
		throw GradeTooHighException("Sign");
	if (executeGrade > 150)
		throw GradeTooLowException("Execute");
	if (executeGrade < 1)
		throw GradeTooHighException("Sign");
	_signed = false;
	std::cout	<< "'" << _name
				<< "' was created" << std::endl;
}

Form::~Form()
{
	std::cout 	<< "'" << _name
				<< "' was ripped apart" << std::endl;
}


// #############################################################################
//			GETTERS
// #############################################################################

const std::string&	Form::getName( void ) const
{
	return _name;
}

bool	Form::isSigned( void ) const
{
	return _signed;
}

int	Form::getSignGrade( void ) const
{
	return _signGrade;
}

int	Form::getExecuteGrade( void ) const
{
	return _executeGrade;
}

void	Form::beSigned( const Bureaucrat& bureaucrat)
{
	if (_signed)
		throw AlreadySignedException();
	else if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException("Bureaucrats");
	else
	{
		_signed = true;
		bureaucrat.signForm(*this);
	}
}

std::ostream&	operator<<(std::ostream& o, const Form& form)
{
	o << "_____";
	o << form.getName();
	o << "_____" << std::endl;
	o << "* Sign grade:\t\t";
	o << form.getSignGrade()<< std::endl;
	o << "* Execute grade:\t";
	o << form.getExecuteGrade()<< std::endl;
	if (form.isSigned())
		o << "* Form is signed" << std::endl;
	else
		o << "* Form is not signed" << std::endl;
	for (unsigned long i = 0; i < form.getName().size() + 10; i++)
		o << "_";
	return o;
}
