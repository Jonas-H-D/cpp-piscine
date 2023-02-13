#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

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

    readFromFile("contacts.txt");
    cout << "All people in my phone book:" << endl << endl;
    myBook->listAllContacts();

    return 0;
}
