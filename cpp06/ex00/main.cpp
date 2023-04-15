#include "Scalaire.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            Scalar scalar(argv[1]);
            std::cout << scalar;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cerr << "Usage: ./convert <value>" << std::endl;
}