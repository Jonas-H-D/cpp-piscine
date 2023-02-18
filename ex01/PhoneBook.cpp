//
// Created by Jonas Hermon-Duc on 10/02/2023.
//
#include "PhoneBook.hpp"
#include <limits>

using namespace std;

PhoneBook::PhoneBook() {
    nr = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::startDisplay(void) {
    cout << "################PHONEBOOK##################" << endl;
    cout << "Enter your command (ADD, SEARCH, EXIT" << endl;
    cout << "command >>>>> ";
}

void PhoneBook::searchDisplay(void) {
    cout << "###########################################" << endl;
    cout  << "INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  "<< endl;
    this->listAllContacts();
    cout << "|-----------------------------------------|" << endl;
}

void    PhoneBook::addContact(string fName, string lName, string niName, string phone, string secret) {
    if (nr == 7) {
        this->deleteLastContacts();
        nr--;
    }
    contacts.push_back(Contact(fName, lName, niName, phone, secret));
    nr++;
}


void PhoneBook::addContact(Contact &contact) {
    this->addContact(contact.getFirstName(), contact.getLastName(), contact.getNickname(), contact.getPhoneNumber(),
                      contact.getDarkestSecret());
}

void printInfo(string info){
    if (info.length() > 10)
        cout << info.substr(0, 9) << "." << "|";
    else
        cout << info << setw((10 - info.length())) << "|";
}

void PhoneBook::listAllContacts() {
    list<Contact>::iterator it;
    int count = 0;
    for (it = contacts.begin(); it != contacts.end(); it++) {
        cout << count << setw(10) << "|";
        printInfo(((Contact) (*it)).getFirstName());
        printInfo(((Contact) (*it)).getLastName());
        printInfo(((Contact) (*it)).getNickname());
        count++;
        cout << endl;
    }
    cout << endl;
}

void PhoneBook::searchContact() {
    list<Contact>::iterator it, itLast;
    int index;
    int iterate = 0;
    this->searchDisplay();
    cout << "Enter index of Contact to display: ";
    cin >> index;
    while(1) {
        if ((cin.fail())) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INDEX is between 0 and 7" << endl;
            cout << "Retry >>> Enter index of Contact to display: ";
            cin >> index;
        }
        if (!cin.fail())
            break;
    }
    for (it = contacts.begin(); it != contacts.end(); it++) {
        if (iterate == index) {
            cout << "FIRST NAME:  " << ((Contact) (*it)).getFirstName() << endl;
            cout << "LAST NAME:   "      << ((Contact) (*it)).getLastName() << endl;
            cout << "NICKNAME:    "      << ((Contact) (*it)).getNickname() << endl;
            cout << "PHONE:       "      << ((Contact) (*it)).getPhoneNumber() << endl;
            cout << "DARKEST SECRET: "  << ((Contact) (*it)).getDarkestSecret() << endl;
            iterate = 0;
        }
        iterate++;
    }
}

void PhoneBook::deleteLastContacts() {
    list<Contact>::iterator it;
    int i = 0;
    for (it = contacts.begin(); it != contacts.end(); it++) {
        i++;
        if (i == 7) {
            ((Contact) (*it)).firstName.clear();
            ((Contact) (*it)).lastName.clear();
            ((Contact) (*it)).nickname.clear();
            ((Contact) (*it)).phoneNumber.clear();
            ((Contact) (*it)).darkestSecret.clear();
        }
    }
}

void PhoneBook::generateContact(PhoneBook *myBook) {
    Contact *myContact = new Contact();
    myContact->setFirstName();
    myContact->setLastName();
    myContact->setNickname();
    myContact->setPhoneNumber();
    myContact->setDarkestSecret();
    myBook->addContact(*myContact);
}