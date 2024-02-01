/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 13:57:12 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/18 16:38:56 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHURBBERYCREATIONFORM_HPP
# define SHURBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm() {};
		ShrubberyCreationForm( const std::string& name );
		~ShrubberyCreationForm();

		void	execute( const Bureaucrat& executor ) const;
};

# define TREE "                                                         .\n" \
"                                              .         ;  \n" \
"                 .              .              ;%     ;;   \n" \
"                   ,           ,                :;%  %;   \n" \
"                    :         ;                   :;%;'     .,   \n" \
"           ,.        %;     %;            ;        %;'    ,;\n" \
"           ,.        %;     %;            ;        %;'    ,;\n" \
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" \
"               ;%;      %;        ;%;        % ;%;  ,%;'\n" \
"                `%;.     ;%;     %;'         `;%%;.%;'\n" \
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n" \
"                    `:%;.  :;bd%;          %;@%;'\n" \
"                      `@%:.  :;%.         ;@@%;'   \n" \
"                        `@%.  `;@%.      ;@@%;        \n" \
"                          `@%%. `@%%    ;@@%;        \n" \
"                            ;@%. :@%%  %@@%;       \n" \
"                              %@bd%%%bd%%:;     \n" \
"                                #@%%%%%:;;\n" \
"                                %@@%%%::;\n" \
"                                %@@@%(o);  . '      \n" \
"                                %@@@o%;:(.,'         \n" \
"                            `.. %@@@o%::;         \n" \
"                               `)@@@o%::;         \n" \
"                                %@@(o)::;        \n" \
"                               .%@@@@%::;         \n" \
"                               ;%@@@@%::;.          \n" \
"                              ;%@@@@%%:;;;. \n" \
"                          ...;%@@@@@%%:;;;;,..    Gilo97\n"

#endif