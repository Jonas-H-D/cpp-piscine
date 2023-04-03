#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat	moses("moses", 3);
    Bureaucrat	david("david", 45);
    PresidentialPardonForm	presidential("tree");
    RobotomyRequestForm		robotomy("garden");
    ShrubberyCreationForm	shrub("sattelite");
    std::cout << moses.getGrade() << std::endl;
    moses.incrementGrade();
    std::cout << moses << std::endl;
    moses.incrementGrade();
    std::cout << moses << std::endl;
    moses.incrementGrade();
    robotomy.beSigned(&moses);
    david.signForm(robotomy);
    shrub.beSigned(&moses);
    shrub.execute(moses);
    moses.signForm(presidential);
    presidential.execute(moses);
    robotomy.execute(david);
    return 0;
}