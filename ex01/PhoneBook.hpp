//
// Created by Jonas Hermon-Duc on 10/02/2023.
//

#ifndef EX01_PHONEBOOK_CLASS_HPP
#define EX01_PHONEBOOK_CLASS_HPP
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"

using namespace std;

class PhoneBook {
    int nr;
    list<Contact> contacts;
public:
    PhoneBook();
    ~PhoneBook();
    void addContact(string fName, string lName, string niName, string phone, string secret);
    void addContact(Contact&);

    void listAllContacts();
    void generateContact(PhoneBook *myBook);
    void searchContact(void);
    void searchDisplay(void);
    void startDisplay(void);
    void deleteAllContacts();

    void deleteLastContacts();
};
#endif //EX01_PHONEBOOK_CLASS_HPP
