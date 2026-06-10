/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:28:27 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/10 19:28:27 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
	// std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	// std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	// std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	// std::cout << "Bureaucrat Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
	// std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string	Bureaucrat::getName() {
	return (this->_name);
}

int					Bureaucrat::getGrade() {
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat& other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return (o);
}