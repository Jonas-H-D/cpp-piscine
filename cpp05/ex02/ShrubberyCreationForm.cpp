//
// Created by Jonas Hermon-Duc on 26/03/2023.
//

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137) {
    _target = "default_target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) {
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): _target(other._target), AForm(other.getName(), other.getSignGrade(), other.getExecGrade()){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    try {
        checkBeforeExecute(executor);
        std::ofstream file;
        file.open(_target + "_shrubbery");
        file << "    oxoxoo    ooxoo\n"
                "  ooxoxo oo  oxoxooo\n"
                " oooo xxoxoo ooo ooox\n"
                " oxo o oxoxo  xoxxoxo\n"
                "  oxo xooxoooo o ooo\n"
                "    ooo\\oo\\  /o/o\n"
                "        \\  \\/ /\n"
                "         |   /\n"
                "         |  |\n"
                "         | D|\n"
                "         |  |\n"
                "         |  |\n"
                "  ______/____\\____" << std::endl;
        file.close();
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}
