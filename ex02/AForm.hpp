/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:34:27 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/06 14:56:25 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool 				_isSigned;
	public:

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		AForm( void );
		AForm( std::string name , int gradeToSign, int gradeToExec );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		~AForm( void );

		std::string	getName( void ) const;
		virtual	int	getGradeToSign( void ) const = 0;
		virtual	int	getGradeToExec( void ) const = 0;

		void		beSigned( Bureaucrat& b );
};

std::ostream& operator<<( std::ostream &o, const AForm &Aform );

#endif