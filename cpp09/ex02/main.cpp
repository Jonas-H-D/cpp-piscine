
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

int main(int argc, char **argv){
    int i = 1;
    std::deque<int> myDeque;
    std::vector<int> myVector;

    int value;
    while (i != argc) {
        value = std::atoi(argv[i]);
        myDeque.push_back(value);
        myVector.push_back(value);
        std::cout << *argv[i] << std::endl;
        i++;
    }
    std::deque<int>::iterator   it;
    for (it = myDeque.begin(); it != myDeque.end(); ++it){
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::vector<int>::iterator  y;
    std::clock_t start = std::clock();
    std::sort(myVector.begin(), myVector.end());
    std::clock_t end = std::clock();
    double duration = (end - start) / (double)CLOCKS_PER_SEC;
    for (y = myVector.begin(); y != myVector.end(); ++y){
        std::cout << *y << ' ';
    }
    std::cout << std::endl;
    std::cout << "time sort processing = " << duration << std::endl;

    return 0;
}