#include "easyfind.hpp"

int main(void){
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(100);
    numbers.push_back(10);
    numbers.push_back(70);
    numbers.push_back(100);
    std::list<int> myList;
    myList.push_back(22);
    myList.push_back(44);
    myList.push_back(78);
    myList.push_back(27);
    myList.push_back(20);
    std::deque<int> myDeque;
    myDeque.push_back(22);
    myDeque.push_back(44);
    myDeque.push_back(78);
    myDeque.push_back(27);
    myDeque.push_back(20);

    std::cout << "Container 1: "  << std::endl;
    easyfind(numbers, 100);
    std::cout << "Container 2: "  << std::endl;
    easyfind(myList, 2);
    std::cout << "Container 3: "  << std::endl;
    easyfind(myList, 390);
    std::cout << "Container 4: "  << std::endl;
    easyfind(myDeque, 27);

    return (0);
}