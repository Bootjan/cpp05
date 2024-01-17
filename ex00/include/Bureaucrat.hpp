/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:45:54 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/16 23:08:16 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
		void	GradeTooLowException( void ) const;
		void	GradeTooHighException( void ) const;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

typedef void (Bureaucrat::*t_func) ( void ) const;

#endif
