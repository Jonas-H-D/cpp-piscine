//
// Created by Jonas Hermon-duc on 3/24/23.
//

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
        std::cerr << e.what() << std::endl;
        return 0;
    }
    _grade = grade;
    return 1;
}

void    Bureaucrat::incrementGrade() {
    if (setGrade(_grade - 1))
        std::cout << "increased " << getName() << " grade" << std::endl;
}

void    Bureaucrat::decrementGrade() {
    if (setGrade(_grade + 1))
        std::cout << "decreased " << getName() << " grade" << std::endl;
}

void	Bureaucrat::signForm(AForm &AForm) {
    if (_grade <= AForm.getSignGrade()){
        AForm.beSigned(this);
    }
    else
        std::cout << _name << " couldn't sign " << AForm.getName() <<
                  " because he doesn't have the required grade to sign this AForm" << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName()
                  << " because of the following error: " << e.what() << std::endl;
    }

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