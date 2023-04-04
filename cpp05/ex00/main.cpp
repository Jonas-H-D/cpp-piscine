#include "Bureaucrat.h"

int main(){
    Bureaucrat  riri("Riri", 120);
    Bureaucrat  malcolm("Malcolm", 3);
    Bureaucrat  def;
    Bureaucrat  *lili = new Bureaucrat("Lili", 4);

    std::cout << def.getGrade() << std::endl;
    std::cout << riri.getGrade() << std::endl;
    std::cout << lili->getName() << " : "<<lili->getGrade() << std::endl;

    std::cout << *lili << std::endl;
    std::cout << riri << std::endl;
    lili->incrementGrade(100);
    delete lili;
    riri.incrementGrade(100);
    riri.setGrade(250);
    std::cout << riri << std::endl;
    malcolm.incrementGrade(1);
    std::cout << malcolm << std::endl;
    malcolm.incrementGrade(1);
    std::cout << malcolm << std::endl;
    malcolm.incrementGrade(1);

    return 0;
}