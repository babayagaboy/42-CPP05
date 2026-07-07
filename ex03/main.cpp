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
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	try
		{
			Bureaucrat boss("Boss", 1);
			Intern someRandomIntern;
			AForm* rrf;

			std::cout << "--- Intern Creates Shrubbery Form ---" << std::endl;
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			if (rrf)
			{
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
				delete rrf;
			}

			std::cout << "\n--- Intern Creates Robotomy Form ---" << std::endl;
			rrf = someRandomIntern.makeForm("robotomy request", "Wall-E");
			if (rrf)
			{
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
				delete rrf;
			}

			std::cout << "\n--- Intern Creates Pardon Form ---" << std::endl;
			rrf = someRandomIntern.makeForm("presidential pardon", "Marvin");
			if (rrf)
			{
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
				delete rrf;
			}

			std::cout << "\n--- Intern Creates Invalid Form ---" << std::endl;
			rrf = someRandomIntern.makeForm("coffee request", "Boss");
			if (rrf)
			{
				delete rrf;
			}
		}
		catch (std::exception const &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		return 0;
}