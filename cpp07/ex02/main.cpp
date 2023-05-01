#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // TEST 1 : Array Object and Array Typed
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Test Array Generation" << std::endl
              << "array[] numbers: ";
    printObjectFunction(numbers, MAX_VAL);
    std::cout << std::endl
              << "array[] mirror: ";
    printTypeFunction(mirror, MAX_VAL);
    std::cout << std::endl;
    // TEST 2 : Copy OPERATOR = and Constructor with Object copy
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Test Array Generation" << std::endl
                  << "array[] tmp: ";
        printObjectFunction(tmp, MAX_VAL);
        std::cout << std::endl
                  << "array[] test: ";
        printObjectFunction(test, MAX_VAL);
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << "Trying to access tab i - 1 : should error" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to access array[MAX_VALUE]. Should error" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}