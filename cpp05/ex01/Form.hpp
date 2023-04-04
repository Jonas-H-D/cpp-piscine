//
// Created by Jonas Hermon-Duc on 26/03/2023.
//

#ifndef CPPPROJECTS_FORM_HPP
#define CPPPROJECTS_FORM_HPP

#include <iostream>
#include "Bureaucrat.h"

class Form {
private:
    std::string const _name;
    bool    _signed;
    int const _sign_grade;
    int const _exec_grade;
public:
    Form();
    Form(std::string const name, int const sign, int const exec);
    Form(Form const &other);
    ~Form();

    Form& operator=(Form const &tmp);

    std::string getName() const;
    bool    getSigned() const;
    int     getSignGrade() const;
    int     getExecGrade() const;
    void beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("Grade is too HIGH for this Form");
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("\033[1;31mGrade is too LOW for this Form\033[0m");
        }
    };
    class FormAlreadySigned : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("\033[1;31m Form is Already Signed\033[0m \U0001F603");
        }
    };
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif
