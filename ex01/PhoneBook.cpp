//
// Created by Jonas Hermon-Duc on 10/02/2023.
//
#include <string>
#include <list>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook() {
    nr = 0;
}

bool PhoneBook::addContact(string fName, string lName, string niName, string phone, string secret) {
    if (nr == 0) {
        contacts.push_back(Contact(fName, lName, niName, phone, secret));
        nr++;
        return true;
    }

    bool found = false;
    list<Contact>::iterator it, itLast;
    for (it = contacts.begin(); it != contacts.end() && found == false; it++) {
        if (((Contact) (*it)).getFirstName().compare(fName) > 0) {
            itLast = it;
            found = true;
        } else if (((Contact) (*it)).getFirstName().compare(fName) == 0) {
            return false;
        }
    }

    if (found == false) {
        contacts.push_back(Contact(fName, lName, niName, phone, secret));
        nr++;
        return true;
    }

    contacts.insert(itLast, Contact(fName, lName, niName, phone, secret));
    nr++;
    return true;
}

bool PhoneBook::addContact(Contact &contact) {
    return addContact(contact.getFirstName(), contact.getLastName(), contact.getNickname(), contact.getPhoneNumber(), contact.getDarkestSecret());
}

void PhoneBook::listAllContacts() {
    list<Contact>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); it++) {
        cout << ((Contact) (*it)).getFirstName() << " | "
                << ((Contact) (*it)).getLastName() << " | "
                    << ((Contact) (*it)).getNickname() << " | "
                        << ((Contact) (*it)).getDarkestSecret() << " | "
                            << ((Contact) (*it)).getPhoneNumber() << endl;
    }
    cout << endl;
}