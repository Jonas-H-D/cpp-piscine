#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    std::cout << "******** previous tests, old code working **************" << std::endl;
    std::cout << "******** Bureaucrat and Form creation **************" << std::endl;
    Bureaucrat	riri("Riri", 4);
    Bureaucrat	malcolm("Malcolm", 150);
    Bureaucrat	ghost("", 120);
    PresidentialPardonForm	presidential("Trump");
    RobotomyRequestForm		robotomy("Jocker");
    ShrubberyCreationForm	shrub("SherryBlossom");
    ShrubberyCreationForm	shrubNull("");
    std::cout << "******** Testing Bureau and Form Functions **************" << std::endl;
    std::cout << "Riri grade: "<<riri.getGrade() << std::endl;
    riri.incrementGrade();
    std::cout << riri << std::endl;
    riri.incrementGrade();
    std::cout << riri << std::endl;
    riri.incrementGrade();
    robotomy.beSigned(&riri);
    malcolm.signForm(robotomy);
    shrub.beSigned(&riri);
    shrub.beSigned(&malcolm);
    std::cout << "******** Testing Execution **************" << std::endl;
    shrub.execute(riri);
    shrubNull.execute(riri);
    riri.signForm(presidential);
    presidential.execute(riri);
    robotomy.execute(ghost);
    return 0;
}