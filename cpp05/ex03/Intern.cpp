//
// Created by Jonas Hermon-duc on 4/3/23.
//

#include "Intern.hpp"

Intern::Intern() {
    _f[0] = &Intern::creatPresidential;
    _f[1] = &Intern::creatRobotomy;
    _f[2] = &Intern::creatShubbery;
    _form[0] = "presidential pardon";
    _form[1] = "robotomy request";
    _form[2] = "shrubbery creation";
}

Intern::~Intern() {}

static std::string	setFormName(std::string name){
    std::cout << "Setting form name " << std::endl;
    if (name == "")
        name = "default_form";
    int s = name.length();
    for (int i = 0; i < s; i++) {
        name[i] = tolower(name[i]);
    }
    std::cout << "form name = "<< name << std::endl;
    return name;
}

AForm	*Intern::makeForm(std::string form, std::string target) {
    AForm *tmp = nullptr;
    for (int i = 0; i < 3; i++) {
        if (form == _form[i]) {
            std::cout << "Intern creates " << form << std::endl;
            if (_f[i]) {
                tmp = (this->*_f[i])(target);
                return tmp;
            } else {
                std::cout << "Error: function pointer is null" << std::endl;
                return nullptr;
            }
        }
    }
    std::cout << "Error: form not found" << std::endl;
    return nullptr;
}

AForm	*Intern::creatPresidential(std::string str) {
    return (new PresidentialPardonForm(str));
}

AForm	*Intern::creatRobotomy(std::string str) {
    return (new RobotomyRequestForm(str));
}

AForm	*Intern::creatShubbery(std::string str) {
    return (new ShrubberyCreationForm(str));
}
