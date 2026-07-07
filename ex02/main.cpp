/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:20:08 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/24 15:20:08 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	{
		try
		{
			Bureaucrat it("Gustavinho", 1);
			ShrubberyCreationForm shru("fofinho");
		
			it.signForm(shru);
			it.executeForm(shru);

			std::cout	<< it.getName()
						<< " signed and executed "
						<< shru.getName()
						<< std::endl;
		}
		catch( const std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat assistant("Assistant", 45);
		Bureaucrat intern("Intern", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Fry");

		std::cout << "--- Shrubbery Tests ---" << std::endl;
		intern.executeForm(shrub);
		assistant.signForm(shrub);
		intern.executeForm(shrub);
		assistant.executeForm(shrub);

		std::cout << "\n--- Robotomy Tests ---" << std::endl;
		assistant.signForm(robot);
		assistant.executeForm(robot);
		boss.executeForm(robot);

		std::cout << "\n--- Presidential Pardon Tests ---" << std::endl;
		boss.signForm(pardon);
		assistant.executeForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}