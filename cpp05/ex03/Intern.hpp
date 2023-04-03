//
// Created by Jonas Hermon-duc on 4/3/23.
//

#ifndef CPP_PISCINE_INTERN_HPP
#define CPP_PISCINE_INTERN_HPP

# include <cctype>
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:
    std::string	_form[3];
    AForm		*(Intern::*_f[3])(std::string str);
    AForm		*creatPresidential(std::string str);
    AForm		*creatRobotomy(std::string str);
    AForm		*creatShubbery(std::string str);
public:
    Intern();
    ~Intern();

    AForm	*makeForm(std::string form, std::string target);
};


#endif //CPP_PISCINE_INTERN_HPP
