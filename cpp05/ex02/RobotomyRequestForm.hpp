//
// Created by Jonas Hermon-Duc on 03/04/2023.
//

#ifndef CPPPROJECTS_ROBOTOMYREQUESTFORM_HPP
#define CPPPROJECTS_ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <cstdlib>
#include <time.h>


class RobotomyRequestForm : public AForm {
private:
    std::string	_target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(RobotomyRequestForm const &tmp);

    void execute(Bureaucrat const &executor) const;
};


#endif //CPPPROJECTS_ROBOTOMYREQUESTFORM_HPP
