#include "Span.hpp"

std::vector<int> generateRandomNumbers(unsigned int count) {
    std::vector<int> numbers;
    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    std::srand(seed);
    for (unsigned int i = 0; i < count; ++i) {
        int number = std::rand();
        numbers.push_back(number);
    }
    return numbers;
}

int main(void){
    std::cout << "-----GENERATING BIG SPAN " << std::endl;
    try {
        Span mySpan(100000);
        std::vector<int> numbers = generateRandomNumbers(100000);
        mySpan.addNumbers(numbers.begin(), numbers.end());

        int shortest = mySpan.shortestSpan();
        int longest = mySpan.longestSpan();
        std::cout << "Shortest span = " << shortest << std::endl;
        std::cout << "Longest span = " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    usleep(1000000);
    std::cout << "-----GENERATING SMALL SPAN " << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(4);
        sp.addNumber(5);
        sp.addNumber(7);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span = " << sp.longestSpan() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----CREATING SPANNY " << std::endl;
    try {
        Span *spanny = new Span(-10000);
        usleep(1000000);

        std::vector<int> newNumbers = generateRandomNumbers(10000);
        spanny->addNumbers(newNumbers.begin(), newNumbers.end());
        int shorty = spanny->shortestSpan();
        int longy = spanny->longestSpan();
        std::cout << "Shortest spanny = " << shorty << std::endl;
        std::cout << "Longest spanny = " << longy<< std::endl;
        delete spanny;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----REACHING SPAN CAPACITY " << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(100);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----CREATING SPANN COPY " << std::endl;
    try {
        Span *spanny = new Span(10000);
        usleep(100000);
        std::vector<int> newNumbers = generateRandomNumbers(10000);
        spanny->addNumbers(newNumbers.begin(), newNumbers.end());
        Span spanCop = *spanny;
        int shortcop = spanCop.shortestSpan();
        int longcop= spanCop.longestSpan();
        std::cout << "Shortest spanny = " << shortcop << std::endl;
        std::cout << "Longest spanny = " << longcop<< std::endl;
        delete spanny;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}