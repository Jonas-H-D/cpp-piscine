//
// Created by Jonas Hermon-Duc on 26/03/2023.
//

#include "Form.hpp"
#include "Bureaucrat.h"

Form::Form() : _name("MyForm"),_signed(false), _sign_grade(150), _exec_grade(120) {

}

Form::Form(std::string const name, int const sign, int const exec) : _name(name),_signed(false), _sign_grade(sign), _exec_grade(exec) {
    if (sign < 1 || exec < 1)
        throw Bureaucrat::GradeTooHighException();
    if (sign > 150 || exec > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade){
}

Form::~Form(){

}

std::string Form::getName() const{
    return _name;
}

bool    Form::getSigned() const{
    return _signed;
}

int     Form::getSignGrade() const{
    return _sign_grade;
}

int     Form::getExecGrade() const{
    return _exec_grade;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    try {
        if (this->_signed == true) {
            std::cout << "\033[1;31m" << getName() << "\033[0m";
            throw Form::FormAlreadySigned();
        } else if (bureaucrat.getGrade() >= this->getSignGrade()) {
            std::cout << "\033[1;31m" << bureaucrat.getName() << " couldn't sign " << _name << " form, because \033[0m";
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        return ;
    }
    _signed = true;
    std::cout << "\033[1;32m" << bureaucrat.getName() << " signed " << _name << " BRAVO \U0001F603\033[0m"
                  << std::endl;
}

Form &Form::operator=(Form const &rhs){
    if (this == &rhs)
        return (*this);
    _signed = rhs.getSigned();
    return *this;
}

std::ostream    &operator<<(std::ostream &out, const Form &tmp){
    if (tmp.getSigned() == true)
        out << "\033[1;32m" <<tmp.getName() << " form status: signed\033[0m";
    else
        out << tmp.getName() << ": form status: not signed; it needs a Bureaucrat at level " << tmp.getSignGrade() << " to be signed";
    return out;
}

