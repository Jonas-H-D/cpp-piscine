#include "Bureaucrat.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    try {
        Bureaucrat	moses("moses", 3);
        Bureaucrat	david("david", 45);
        PresidentialPardonForm	presidential("tree");
        RobotomyRequestForm		robotomy("garden");
        ShrubberyCreationForm	shrub("sattelite");
        std::cout << moses.getGrade() << std::endl;
        moses.incrementGrade(10);
        std::cout << moses << std::endl;
        moses.incrementGrade(10);
        std::cout << moses << std::endl;
        moses.incrementGrade(10);
        robotomy.beSigned(&moses);
        david.signForm(robotomy);
        shrub.beSigned(&moses);
        shrub.execute(moses);
        moses.signForm(presidential);
        presidential.execute(moses);
        robotomy.execute(david);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    return 0;
}