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

void identify(Base& p) {
    if (A* a = dynamic_cast<A*>(&p)) {
        std::cout << "class type: A" << std::endl;
    }
    else if (B* b = dynamic_cast<B*>(&p)) {
        std::cout << "class type: B" << std::endl;
    }
    else if (C* c = dynamic_cast<C*>(&p)) {
        std::cout << "class type: C" << std::endl;
    }
}

int	main() {
    srand(time(NULL));
    //generating random drived class
    Base*	pointer_a = generate();
    //and one more
    Base*	pointer_b = generate();
    //checking their types by pointer
    identify(pointer_a);
    identify(pointer_b);
    //checking their types by reference
    identify(*pointer_a);
    identify(*pointer_b);
    return 0;
}