/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 11:50:40 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:02:13 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade = 150;
		const int			_executeGrade = 150;
	public:
		Form() {};
		Form(const std::string& name, int signGrade, int executeGrade);
		~Form();

		const std::string&	getName( void ) const;
		bool				isSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;
		void				beSigned( const Bureaucrat& bureaucrat );

		struct ExecuteException : public std::runtime_error
		{
			ExecuteException(const std::string &message) : std::runtime_error(message) {}
		};

		struct GradeTooLowException : public ExecuteException
		{
			GradeTooLowException(const std::string& message) : ExecuteException(message + " grade too low") {}
		};

		struct GradeTooHighException : public ExecuteException
		{
			GradeTooHighException(const std::string& message) : ExecuteException(message + " grade too low") {}
		};

		struct AlreadySignedException : public ExecuteException
		{
			AlreadySignedException() : ExecuteException("Form already signed") {}
		};
};

typedef void (Form::*t_funcF) ( void ) const;

std::ostream&	operator<<(std::ostream& o, const Form& form);

#endif
