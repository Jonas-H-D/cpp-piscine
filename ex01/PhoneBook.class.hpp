//
// Created by Jonas Hermon-Duc on 10/02/2023.
//

#ifndef EX01_PHONEBOOK_CLASS_HPP
#define EX01_PHONEBOOK_CLASS_HPP
#include <string>
#include <list>
#include "Contact.class.hpp"

using namespace std;

class PhoneBook {
    int nr;
    list<Contact> contacts;
public:
    PhoneBook();

    bool addContact(string fName, string lName, string niName, string phone, string secret);
    bool addContact(Contact&);

    void listAllContacts();
};
#endif //EX01_PHONEBOOK_CLASS_HPP
