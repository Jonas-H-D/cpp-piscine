//
// Created by Jonas Hermon-Duc on 28/03/2023.
//

#ifndef CPPPROJECTS_AFORM_HPP
#define CPPPROJECTS_AFORM_HPP
#include "Bureaucrat.h"

class AForm {
private:
    std::string const _name;
    bool    _signed;
    int const _sign_grade;
    int const _exec_grade;
public:
    AForm();
    AForm(std::string const name, int const sign, int const exec);
    AForm(AForm const &other);
    ~AForm();

    AForm& operator=(AForm const &tmp);

    std::string getName() const;
    bool        getSigned() const;
    int         getSignGrade() const;
    int         getExecGrade() const;
    void        beSigned(Bureaucrat const &bureaucrat);
    void	    checkBeforeExecute(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const &executor) const = 0;


    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("Grade is too HIGH for this Form");
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("Grade is too LOW for this Form");
        }
    };
    class FormAlreadySigned : public std::exception {
    public:
        virtual const char *what() const throw(){
            return ("\033[1;31m Form is Already Signed\033[0m \U0001F603");
        }
    };
    class UnsignedFormException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Error: form is not signed");
        }
    };
};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif //CPPPROJECTS_AFORM_HPP
