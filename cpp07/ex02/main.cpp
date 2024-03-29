#include <iostream>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 10
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

    Array<char> letters(MAX_VAL);
    char let = 'a';
    for (int i = 0; i < MAX_VAL; i++)
    {
        letters[i] = let++;
    }
    std::cout << "Test Array Generation" << std::endl
              << "*** array[] letters ***: ";
    printObjectFunction(letters, MAX_VAL);
    std::cout << std::endl;

    Array<std::string> words(MAX_VAL);
    std::string mots[MAX_VAL] = {"hello", "the", "world"};
    for (int i = 0; i < MAX_VAL && i < words.size(); i++)
    {
        words[i] = mots[i];
    }
    std::cout << "Test Array Generation" << std::endl
              << "*** array[] words ***: ";
    printObjectFunction(words, MAX_VAL);
    std::cout << std::endl;

    Array<float> floatty(MAX_VAL);
    float* oppo = new float[MAX_VAL];
    std::srand(std::time(nullptr));
    for (int i = 0; i < MAX_VAL; i++)
    {
        float x = static_cast<float>(std::rand()) / RAND_MAX;
        floatty[i] = x;
        oppo[i] = x;
    }
    std::cout << "Test Array Generation" << std::endl
              << "array[] floatty: ";
    printObjectFunction(floatty, MAX_VAL);
    std::cout << std::endl
              << "array[] oppo: ";
    printTypeFunction(oppo, MAX_VAL);
    std::cout << std::endl;

    delete [] mirror;
    delete [] oppo;
    return 0;
}