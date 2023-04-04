//
// Created by Jonas Hermon-Duc on 03/04/2023.
//

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialRequest", 72, 45) {
    _target = "default__presidential_target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialRequest", 72, 45) {
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): _target(other._target), AForm(other.getName(), other.getSignGrade(), other.getExecGrade()){
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    try
    {
        checkBeforeExecute(executor);
        std::cout << "\033[1;32m" << _target << " has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}