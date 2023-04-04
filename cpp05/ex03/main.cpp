#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    std::cout << "******** previous tests, old code working **************" << std::endl;
    std::cout << "******** Bureaucrat and Form creation **************" << std::endl;
    Bureaucrat	riri("Riri", 4);
    Bureaucrat	malcolm("Malcolm", 70);
    Bureaucrat	ghost("", 120);
    ghost = malcolm;
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
    std::cout << "******** Testing Intern Functions **************" << std::endl;
    Intern	intern;
    AForm	*form;
    AForm   *form2;
    AForm   *form3;
    form = intern.makeForm("ro", "Christoph");
    form2 = intern.makeForm("presidential pardon", "Marc");
    form3 = intern.makeForm("", "Christoph");
    Bureaucrat	bouffon("bouffon", 3);
    form->beSigned(&bouffon);
    if (form)
        form->execute(bouffon);
    return 0;
}