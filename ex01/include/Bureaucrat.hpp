/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 22:45:54 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/18 16:04:38 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat() {};
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat() ;
		const std::string&	getName( void ) const;
		int					getGrade( void ) const;
		void	Promotion( void );
		void	Demotion( void );
		void	signForm( Form& form ) const;

		struct ExecuteException : public std::runtime_error
		{
			ExecuteException(const std::string &message) : std::runtime_error(message) {}
		};

		struct GradeTooLowException : public ExecuteException
		{
			GradeTooLowException() : ExecuteException("Grade too low") {}
		};

		struct GradeTooHighException : public ExecuteException
		{
			GradeTooHighException() : ExecuteException("Grade too high") {}
		};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

typedef void (Bureaucrat::*t_func) ( void ) const;

#endif
