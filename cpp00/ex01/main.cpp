
#include "PhoneBook.hpp"

int main(int argc, char** argv) {
    PhoneBook myBook;
    std::string command;
    bool run;

    run = true;
    while (run) {
        myBook.start_display();
        getline(std::cin, command);
        if (command == "ADD") {
            myBook.add_contact();
        }
        if (command == "SEARCH") {
            myBook.search_contact();
        }
        if (command == "EXIT") {
            std::cout << "Exiting program" << std::endl;
            run = false;
        }
    }
    return 0;
}