#include "iter.hpp"

char    myUpper(char c)
{
    char    C;

    C = std::toupper(c);
    std::cout << "toUpperChar:" << C << std::endl;
    return (C);
}

int main(){
    double tab[]= {12, 124, 219, 3498, 12.4};
    std::string table2[] = {"hi", "this", "is", "me"};
    char tab3[] = {'h', 'E', 'l', 'l'};
    std::size_t sizeTab;

    sizeTab = sizeof(tab) / sizeof(double);
    iter(tab, sizeTab, add2<double>);
    sizeTab = sizeof(table2) / sizeof(std::string);
    iter(table2, sizeTab, functionPrint<std::string>);
    sizeTab = sizeof(tab3) / sizeof(char);
    iter(tab3, sizeTab, functionPrint<char>);
    iter(tab3, sizeTab, myUpper);
}