#include "PmergeMe.hpp"

int main(int argc, char **argv){

    if (argc < 2){
        std::cout << "ERROR - Program works as follow: ./merge + int positive values to sort+" << std::endl;
        return 0;
    }
    std::cout << "First Instance" << std::endl;
    PmergeMe merge(argc,argv);

    std::cout << "Second Instance" << std::endl;
    PmergeMe  hello(argc, argv);

    std::cout << "Operator = Surcharge" << std::endl;
    hello = merge;
    hello.sortAndPrint();
    std::cout << "Other object as Argument" << std::endl;
    PmergeMe test(merge);

    return 0;
}