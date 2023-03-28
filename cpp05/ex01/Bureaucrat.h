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
    void    signForm();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("\033[1;31mGrade is too HIGH, it has to be Max 1 \033[0m \U0001F621");
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("\033[1;31mGrade is too LOW, Min is 150\033[0m \U0001F621");
        }
    };
};
std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif
