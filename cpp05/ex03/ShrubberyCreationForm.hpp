//
// Created by Jonas Hermon-Duc on 26/03/2023.
//

#ifndef CPPPROJECTS_ShrubberyCreationForm_HPP
#define CPPPROJECTS_ShrubberyCreationForm_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(ShrubberyCreationForm const &tmp);

    void execute(Bureaucrat const &executor) const;
};

#endif
