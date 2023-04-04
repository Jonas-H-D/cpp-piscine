//
// Created by Jonas Hermon-duc on 3/24/23.
//

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("Marc"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name), _grade(other._grade){
}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

int Bureaucrat::setGrade(int grade){
    try{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const std:: exception& e){
        std::cerr << "\033[1;31m" <<this->getName()<< ": " << e.what()<< "\033[0m" << std::endl;
        return 0;
    }
    _grade = grade;
    return 1;
}

void    Bureaucrat::incrementGrade(int i) {
    if (setGrade(_grade - i))
        std::cout << "increased " << getName() << " grade" << std::endl;
}

void    Bureaucrat::decrementGrade(int i) {
    if (setGrade(_grade + i))
        std::cout << "decreased " << getName() << " grade" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
    if (this == &rhs)
        return (*this);
    this->_grade = rhs.getGrade();
    return *this;
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &tmp){
    out << tmp.getName() << " bureaucrat grade = " << tmp.getGrade() << ".";
    return out;
}