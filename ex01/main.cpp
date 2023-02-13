#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;

PhoneBook *myBook;

void readFromFile(string fname) {
    int n = 0, i;
    string fName, lName, nName, phone, secret, nstr;
    ifstream fin(fname.c_str());

    getline(fin, nstr);
    n = atoi(nstr.c_str());

    for (i = 0; i < n; i++) {
        getline(fin, fName);
        getline(fin, phone);

        myBook->addContact(fName, lName, nName, phone, secret);
    }

    fin.close();
}

int main(int argc, char** argv) {
    myBook = new PhoneBook();
    string fName, lName, nName, phone, secret;
    string command;

    readFromFile("contacts.txt");
    cout << "All people in my phone book:" << endl << endl;
    myBook->listAllContacts();

    cout << "command: ";
    cin >> command;
    if (command == "ADD"){
        cout << "First Name:";
        cin >> fName;
        cout << "Last Name:";
        cin >> lName;
        cout << "NickName:";
        cin >> nName;
        cout << "phone:";
        cin >> phone;
        cout << "Darkest secret:";
        cin >> secret;
        myBook->addContact(fName, lName, nName, phone, secret);
    }
    else
        cout << "What??";
    myBook->listAllContacts();
    return 0;
}
