#include "iter.hpp"

int main(){
    double tab[]= {12, 124, 219, 3498, 12.4};
    std::string tab2[] = {"hi", "this", "is", "me"};
    char tab3[] = {'h', 'E', 'l', 'l'};
    std::size_t sizeTab;

    sizeTab = sizeof(tab) / sizeof(double);
    iter(tab, sizeTab, function<double>);
    sizeTab = sizeof(tab2) / sizeof(std::string);
    iter(tab2, sizeTab, function<std::string>);
    sizeTab = sizeof(tab3) / sizeof(char);
    iter(tab3, sizeTab, function<char>);
}