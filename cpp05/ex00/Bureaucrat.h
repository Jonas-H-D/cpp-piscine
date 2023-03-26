//
// Created by Jonas Hermon-duc on 3/24/23.
//

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    ~Bureaucrat();

    Bureaucrat& operator=(Bureaucrat const &rhs);

    std::string getName() const;
    int     getGrade() const;
    int     setGrade(int grade);
    void    incrementGrade(int i);
    void    decrementGrade(int i);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("Grade is too HIGH, it has to be between 1 and 150");
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("Grade is too LOW, it has to be between 1 and 150");
        }
    };
};
std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif
