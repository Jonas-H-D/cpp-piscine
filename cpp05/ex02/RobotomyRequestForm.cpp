//
// Created by Jonas Hermon-Duc on 03/04/2023.
//

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotRequest", 72, 45) {
    _target = "default__robot_target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotRequest", 72, 45) {
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): _target(other._target), AForm(other.getName(), other.getSignGrade(), other.getExecGrade()){
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    try
    {
        checkBeforeExecute(executor);
        std::cout << "Bzzzzzzzz Bzzzzzzzz Bzzzzzzz" << std::endl;
        std::srand(time(NULL));
        int ran  = std::rand();
        if (ran % 2) {
            std::cout << _target << " has been robotomized successfully" << std::endl;
        }
        else {
            std::cout << "Oups! our robotomy failed :F" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
