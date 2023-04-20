#include "Scalaire.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Please enter valid command: ./convert <value>" << std::endl;
        return (0);
    }
    try
    {
        Scalar scalar(argv[1]);
        std::cout << scalar;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}