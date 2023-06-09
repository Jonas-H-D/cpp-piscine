#include "PmergeMe.hpp"

int main(int argc, char **argv){

    if (argc < 2){
        std::cout << "ERROR - Program works as follow: ./PmergeMe + int positive values to sort" << std::endl;
        return 0;
    }
    PmergeMe merge(argc,argv);

    PmergeMe  hello(argc, argv);

    std::cout << "Operator = Surcharge" << std::endl;
    hello = merge;
    hello.sortAndPrint();
    std::cout << "Other object as Argument" << std::endl;
    PmergeMe test(merge);

    return 0;
}