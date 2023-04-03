#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
//    Bureaucrat	moses("moses", 3);
//    Bureaucrat	david("david", 45);
//    PresidentialPardonForm	presidential("tree");
//    RobotomyRequestForm		robotomy("garden");
//    ShrubberyCreationForm	shrub("sattelite");
//    std::cout << moses.getGrade() << std::endl;
//    moses.incrementGrade();
//    std::cout << moses << std::endl;
//    moses.incrementGrade();
//    std::cout << moses << std::endl;
//    moses.incrementGrade();
//    robotomy.beSigned(&moses);
//    david.signForm(robotomy);
//    shrub.beSigned(&moses);
//    shrub.execute(moses);
//    moses.signForm(presidential);
//    presidential.execute(moses);
//    robotomy.execute(david);
    Intern	intern;
    AForm	*form;
    AForm   *form2;
    AForm   *form3;
    form = intern.makeForm("ro", "Christoph");
    std::cout << "MakeForm Finished" << std::endl;
    form2 = intern.makeForm("presidential pardon", "Marc");
    form3 = intern.makeForm("", "Christoph");
    Bureaucrat	bouffon("bouffon", 3);
    form->beSigned(&bouffon);
    //form->execute(bouffon);
    return 0;
}