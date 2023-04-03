//
// Created by Jonas Hermon-Duc on 03/04/2023.
//

#ifndef CPPPROJECTS_PRESIDENTIALPARDONFORM_HPP
#define CPPPROJECTS_PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
private:
    std::string	_target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(PresidentialPardonForm const &tmp);

    void execute(Bureaucrat const &executor) const;
};


#endif //CPPPROJECTS_PRESIDENTIALPARDONFORM_HPP
