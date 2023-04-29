#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {

    int num = 1+ rand() % 3;
    A *a = new A();
    B *b = new B();
    C *c = new C();

    std::cout << "rand num: "<< num << std::endl;
    if (num == 1) {
        delete b;
        delete c;
        return reinterpret_cast<Base *>(a);
    }
    else if (num == 2){
        delete a;
        delete c;
        return reinterpret_cast<Base *>(b);
    }
    else{
        delete b;
        delete a;
        return reinterpret_cast<Base *>(c);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "class type: A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "class type: B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "class type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void	identify(Base& p) {
    Base base;
    try {
        base = dynamic_cast<A&>(p);
        std::cout << "class type: A" << std::endl;
    } catch(const std::exception& e) {}
    try {
        B & b = dynamic_cast<B&>(base);
        std::cout << "class type: B" << std::endl;
    } catch(const std::exception& e) {}
    try {
        base = dynamic_cast<C&>(p);
        std::cout << "class type: C" << std::endl;
    } catch(const std::exception& e) {}
}

int	main() {
    srand(time(NULL));
    std::cout << "Generating random class" << std::endl;
    Base*	pointer_a = generate();
    Base*	pointer_b = generate();
    std::cout << "checking types by pointer" << std::endl;
    identify(pointer_a);
    identify(pointer_b);
    std::cout << "checking types by ref" << std::endl;
    identify(*pointer_a);
    identify(*pointer_b);
    return 0;
}