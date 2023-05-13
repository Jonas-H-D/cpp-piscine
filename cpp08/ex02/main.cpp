#include "MutantStack.hpp"
int main()
{
 std::cout << "-------This IS THE MUTANT STACK" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "-------This IS THE ** CONST ** MUTANT STACK" << std::endl;
    MutantStack<const int> cstack;
    cstack.push(5);
    cstack.push(17);
    std::cout << cstack.top() << std::endl;
    cstack.pop();
    std::cout << cstack.size() << std::endl;
    cstack.push(3);
    cstack.push(5);
    cstack.push(737);
//[...]
    cstack.push(0);
    MutantStack<const int>::const_iterator cit = cstack.cbegin();
    MutantStack<const int>::const_iterator cite = cstack.cend();
    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::stack<const int> c(cstack);

    std::cout << "-------This IS THE LIST" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
//[...]
    lstack.push_back(0);
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    ++it;
    --it;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::list<int> l(lstack);

    std::cout << "-------This IS THE VECTOR" << std::endl;
    std::vector<int> vstack;
    vstack.push_back(5);
    vstack.push_back(17);
    std::cout << vstack.back() << std::endl;
    vstack.pop_back();
    std::cout << vstack.size() << std::endl;
    vstack.push_back(3);
    vstack.push_back(5);
    vstack.push_back(737);
    //[...]
    vstack.push_back(0);
    std::vector<int>::iterator vit = vstack.begin();
    std::vector<int>::iterator vite = vstack.end();
    ++vit;
    --vit;
    while (vit != vite) {
        std::cout << *vit << std::endl;
        ++vit;
    }
    std::vector<int> v(vstack);

    std::cout << "-------STACK OF STRINGS" << std::endl;
    MutantStack<std::string> cityStack;
    cityStack.push("London");
    cityStack.push("Paris");
    cityStack.push("New York");
    cityStack.pop();
    cityStack.push("Tokyo");
    cityStack.push("Sydney");
    std::cout << "Cities in the stack:" << std::endl;
    MutantStack<std::string>::iterator it2 = cityStack.begin();
    MutantStack<std::string>::iterator ite2 = cityStack.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    MutantStack<std::string> city(cityStack);
    return 0;
}