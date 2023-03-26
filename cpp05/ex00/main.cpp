#include "Bureaucrat.h"

int main(){
    Bureaucrat  bob("Bob", 120);
    Bureaucrat  moses("Mois", 3);
    Bureaucrat  def;
    Bureaucrat  *lili = new Bureaucrat("Lili", 4);

    std::cout << def.getGrade() << std::endl;
    std::cout << bob.getGrade() << std::endl;
    std::cout << lili->getName() << " : "<<bob.getGrade() << std::endl;

    std::cout << *lili << std::endl;
    lili->incrementGrade(100);
    delete lili;
    bob.incrementGrade(100);
    std::cout << bob << std::endl;
    moses.incrementGrade(1);
    std::cout << moses << std::endl;
    moses.incrementGrade(1);
    std::cout << moses << std::endl;
    moses.incrementGrade(1);

    return 0;
}