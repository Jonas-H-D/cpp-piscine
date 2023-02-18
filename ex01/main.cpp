#include <iostream>
#include <string>
#include "PhoneBook.hpp"

using namespace std;

PhoneBook *myBook;

int main(int argc, char** argv) {
    myBook = new PhoneBook();
    string command;

    while (command != "EXIT") {
        myBook->startDisplay();
        cin >> command;
        if (command == "ADD") {
            myBook->generateContact(myBook);
        }
        if (command == "SEARCH") {
            myBook->searchContact();
        }
        if (command == "EXIT") {
            cout << "Exiting program" << endl;
            exit(1);
        }
    }
    return 0;
}