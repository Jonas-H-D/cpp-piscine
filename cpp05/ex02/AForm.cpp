//
// Created by Jonas Hermon-Duc on 28/03/2023.
//

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.h"

AForm::AForm() : _name("MyAForm"),_signed(false), _sign_grade(150), _exec_grade(120) {

}

AForm::AForm(std::string const name, int const sign, int const exec) : _name(name),_signed(false), _sign_grade(sign), _exec_grade(exec) {
    if (sign < 1 || exec < 1)
        throw Bureaucrat::GradeTooHighException();
    if (sign > 150 || exec > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(AForm const &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade){
}

AForm::~AForm(){

}

std::string AForm::getName() const{
    return _name;
}

bool    AForm::getSigned() const{
    return _signed;
}

int     AForm::getSignGrade() const{
    return _sign_grade;
}

int     AForm::getExecGrade() const{
    return _exec_grade;
}

void	AForm::checkBeforeExecute(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    try {
        if (this->_signed == true) {
            std::cout << "\033[1;31m"<< getName();
            throw AForm::FormAlreadySigned();
        } else if (bureaucrat.getGrade() >= this->getSignGrade()) {
            std::cout << bureaucrat.getName() << " couldn't sign " << _name << " AForm, because ";
            throw AForm::GradeTooLowException();
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

AForm &AForm::operator=(AForm const &rhs){
    if (this == &rhs)
        return (*this);
    _signed = rhs.getSigned();
    return *this;
}

std::ostream    &operator<<(std::ostream &out, const AForm &tmp){
    if (tmp.getSigned() == true)
        out << "\033[1;32m" <<tmp.getName() << " form status: signed\033[0m";
    else
        out << tmp.getName() << " form status: not signed; it needs a Bureaucrat at level " << tmp.getSignGrade() << " to be signed";
    return out;
}