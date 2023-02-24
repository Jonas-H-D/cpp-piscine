
#include "PhoneBook.hpp"

using namespace std;

int main(int argc, char** argv) {
    PhoneBook myBook;
    string command;
    bool run;

    run = true;
    while (run) {
        myBook.start_display();
        getline(cin, command);
        if (command == "ADD") {
            myBook.add_contact();
        }
        if (command == "SEARCH") {
            myBook.search_contact();
        }
        if (command == "EXIT") {
            cout << "Exiting program" << endl;
            run = false;
        }
    }
    return 0;
}