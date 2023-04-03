//
// Created by Jonas Hermon-Duc on 03/04/2023.
//

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

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
        std::cout << "\033[1;32mBzzzzzzzz Bzzzzzzzz Bzzzzzzz" << std::endl;
        std::srand(time(NULL));
        int ran  = std::rand();
        if (ran % 2) {
            std::cout << _target << " has been robotomized successfully\033[0m" << std::endl;
        }
        else {
            std::cout << "\033[1;31mOups! our robotomy failed :F\033[0m" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
