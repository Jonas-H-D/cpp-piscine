#include "Bureaucrat.h"
#include "Form.hpp"

int main(){
    Bureaucrat  bob("Bob", 120);
    Bureaucrat  momo("Momo", 3);
    Bureaucrat  def;
    Bureaucrat  *lili = new Bureaucrat("Lili", 4);

    std::cout << lili->getName() << " : "<<lili->getGrade() << std::endl;
    def = *lili;
    Form a3("a3", 140, 140);
    Form a1;
    Form a25;

    lili->incrementGrade(100);
    a3.beSigned(*lili);
    a3.beSigned(def);
    a1.beSigned(bob);
    std::cout << momo << std::endl;
    momo.decrementGrade(120);
    std::cout << momo << std::endl;
    a3.beSigned(momo);
    std::cout << a25 << std::endl;
    a1 = a3;
    Form last("last", 3, 1);

    last.beSigned(momo);
    std::cout << a3 << std::endl;

    delete lili;
    return 0;
}