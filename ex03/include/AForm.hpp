/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 11:50:40 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:39:35 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade = 150;
		const int			_executeGrade = 150;
	public:
		AForm() {};
		AForm(const std::string& name, int signGrade, int executeGrade);
		virtual ~AForm();

		const std::string&	getName( void ) const;
		bool				isSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;
		void				beSigned( const Bureaucrat& bureaucrat );
		virtual void		execute( const Bureaucrat& executor ) const = 0;

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

		struct NotSignedException : public ExecuteException
		{
			NotSignedException() : ExecuteException("Form not signed yet") {}
		};
};


typedef void (AForm::*t_funcF) ( void ) const;

std::ostream&	operator<<(std::ostream& o, const AForm& form);

#endif
